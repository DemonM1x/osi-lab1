//
// Created by slava on 23.11.2024.
//

#include "Shell.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "../bench/CreateProcessHelper.hpp"

int main() {
  std::cout << "Shell started. Enter commands in the format: start <num_processes> <command_name>\n";

  while (true) {
    std::cout << "> ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
      continue;
    }

    std::istringstream iss(input);
    std::string command;
    iss >> command;

    if (command == "exit") {
      std::cout << "Exiting shell.\n";
      break;
    }

    if (command != "start") {
      std::cerr << "Unknown command. Use 'start <num_processes> <command_name>' or 'exit' to quit.\n";
      continue;
    }

    int num_processes;
    if (!(iss >> num_processes) || num_processes <= 0) {
      std::cerr << "Invalid number of processes. Please provide a positive integer.\n";
      continue;
    }

    std::string executable;
    std::getline(iss, executable);

    if (executable.empty()) {
      std::cerr << "Executable command not provided.\n";
      continue;
    }

    // Удаляем начальные пробелы из executable
    executable.erase(0, executable.find_first_not_of(" "));

    std::cout << "Starting " << num_processes << " instances of command: " << executable << "\n";

    std::vector<std::thread> threads;
    for (int i = 0; i < num_processes; ++i) {
      threads.emplace_back([&executable]() {
        CreateProcessHelper helper;
        int result = helper.execute_process("monolith.exe", executable);
        if (result != 0) {
          std::cerr << "Process exited with code: " << result << "\n";
        } else {
          std::cout << "Process completed successfully.\n";
        }
      });
    }

    // Ожидаем завершения всех потоков
    for (auto& thread : threads) {
      if (thread.joinable()) {
        thread.join();
      }
    }

    std::cout << "All processes completed.\n";
  }

  return 0;
}

