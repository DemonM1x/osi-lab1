#include "Rm.hpp"
#include <iostream>
#include <filesystem>

void Rm::Run() {
//  std::cout << "Usage: rm <file_or_directory>\n";
}

void Rm::Run(const std::vector<std::string>& args) {
  if (args.empty()) {
    std::cerr << "Error: No file or directory specified. Usage: rm <file_or_directory>\n";
    return;
  }

  const std::string& path = args[0];

  try {
    if (std::filesystem::exists(path)) {
      if (std::filesystem::is_directory(path)) {
        std::filesystem::remove_all(path);  // Удаление директории и её содержимого
      } else {
        std::filesystem::remove(path);  // Удаление файла
      }
      std::cout << "Deleted: " << path << "\n";
    } else {
      std::cerr << "Error: File or directory does not exist: " << path << "\n";
    }
  } catch (const std::filesystem::filesystem_error& e) {
    std::cerr << "Error: " << e.what() << "\n";  // Выводим сообщение об ошибке при неудаче удаления
  }
}

