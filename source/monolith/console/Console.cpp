#include "Console.hpp"
#include "CommandFactory.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>  // Include for timing

#ifdef _WIN32
#include <io.h>
#include <windows.h>
#include <cstdlib>
#else
#include <unistd.h>  // For fork(), execvp(), getcwd() on UNIX
#include <sys/wait.h>
#endif

// Function for getting the current working directory
std::pair<std::string, int> pwd() {
  char cwd[1024];
#ifdef _WIN32
  if (_getcwd(cwd, sizeof(cwd)) != nullptr) {
#else
  if (getcwd(cwd, sizeof(cwd)) != nullptr) {
#endif
    return {std::string(cwd), 0};
  } else {
    perror("pwd");
    return {"", 1};
  }
}

// Function for splitting a string into tokens
std::vector<std::string> SplitString(const std::string& line) {
  std::vector<std::string> tokens;
  std::istringstream stream(line);
  std::string token;

  while (stream >> token) {
    tokens.push_back(token);
  }

  return tokens;
}

//void Console::StartProcess() {
//  std::cout << "Input command " << std::endl;
//  auto [pwd_string, pwd_status_code] = pwd();
//  if (pwd_status_code != 0) {
//    std::cout << "Failed to initialize working directory." << std::endl;
//    return;
//  }
//  std::cout << "Current working directory is: " << pwd_string << std::endl;
//  working_directory_ = pwd_string;
//  this->Run();
//}

void Console::Run(int argc, char** argv) {
    std::string command_string;

    for (int i = 1; i < argc; ++i) { // Пропускаем argv[0], т.к. это имя программы
      command_string += argv[i];
      if (i < argc - 1) {
        command_string += " "; // Добавляем пробел между аргументами
      }
    }
    auto token_list = SplitString(command_string);
    if (token_list.empty()) {
      return;
    }

    std::string command_name = token_list[0];  // Command name
    std::vector<std::string> args(token_list.begin() + 1, token_list.end());

    auto command = factory_.CreateCommand(command_name, args);  // Attempt to create command

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    if (command != nullptr) {
      if (!args.empty()) {
        command->Run(args);  // Передаём аргументы, если они есть
      } else {
        command->Run();  // Вызываем Run() без аргументов
      }
    } else {
      // Convert arguments to char* for execvp
      std::vector<char*> c_args;
      for (const auto& arg : args) {
        c_args.push_back(const_cast<char*>(arg.c_str()));
      }
      c_args.push_back(nullptr);  // execvp requires nullptr at the end

      ExecuteCommand(c_args);  // If command not found, execute system command
    }

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Output the execution time
    std::cout << "Command executed in: " << elapsed.count() << " seconds" << std::endl;

    this->history_.push(command_string);
    std::cin.get();
}

void Console::ExecuteCommand(const std::vector<char*>& args) {
#ifdef _WIN32
  // Assemble the command into a single string
  std::string command;
  for (const auto& arg : args) {
    if (arg != nullptr) {
      command += arg;
      command += " ";
    }
  }

  // Create a structure to launch the process
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  std::cout << "Executing command: " << command << std::endl; // Debug

  // Launch the process
  if (!CreateProcess(nullptr, const_cast<char*>(command.c_str()), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi)) {
    std::cerr << "CreateProcessHelper failed (" << GetLastError() << ")." << std::endl;
    return;
  }

  // Wait for the process to finish
  WaitForSingleObject(pi.hProcess, INFINITE);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
#else
  pid_t pid = fork();
  if (pid < 0) {
    // Error while forking
    perror("fork failed");
    return;
  } else if (pid == 0) {
    // Child process
    std::cout << "Executing command: " << args[0] << std::endl; // Debug
    if (execvp(args[0], args.data()) == -1) {
      perror("execvp failed");
      exit(EXIT_FAILURE); // Terminate child process on error
    }
  } else {
    // Parent process
    int status;
    waitpid(pid, &status, 0); // Wait for child process to finish
    if (WIFEXITED(status)) {
      std::cout << "Process exited with status: " << WEXITSTATUS(status) << std::endl;
    } else {
      std::cout << "Process terminated abnormally." << std::endl;
    }
  }
#endif
}

std::string Console::ReadNextCommandString() {
  std::string command_string;
  std::getline(std::cin, command_string);
  return command_string;
}

Console::Console(CommandFactory& factory) : factory_(factory) {}
