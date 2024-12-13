#include "CreateProcessHelper.hpp"
#include <windows.h>
#include <iostream>

int CreateProcessHelper::execute_process(const std::string& executable, const std::string& args) {
  std::string command_line = executable + " " + args;

  STARTUPINFOA si = { sizeof(STARTUPINFOA) };
  PROCESS_INFORMATION pi = {};

  if (!CreateProcessA(
          nullptr,               // Application name (null to use command line)
          command_line.data(),   // Command line to execute
          nullptr,               // Process security attributes
          nullptr,               // Thread security attributes
          FALSE,                 // Handle inheritance
          CREATE_NEW_CONSOLE,    // Flags to create a new console
          nullptr,               // Environment (null inherits from parent)
          nullptr,               // Current directory (null uses parent's directory)
          &si,                   // Pointer to STARTUPINFOA structure
          &pi                    // Pointer to PROCESS_INFORMATION structure
      )) {
    std::cerr << "Failed to create process. Error: " << GetLastError() << "\n";
    return -1;
  }

  // Wait for the process to complete
  WaitForSingleObject(pi.hProcess, INFINITE);

  // Get the exit code
  DWORD exit_code;
  if (!GetExitCodeProcess(pi.hProcess, &exit_code)) {
    std::cerr << "Failed to get exit code. Error: " << GetLastError() << "\n";
    return -1;
  }

  // Clean up process handles
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  return static_cast<int>(exit_code);
}
