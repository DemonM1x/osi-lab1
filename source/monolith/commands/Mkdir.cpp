#include "Mkdir.hpp"
#include <iostream>
#include <filesystem>

void Mkdir::Run(const std::vector<std::string>& args) {
  if (args.empty()) {
    std::cout << "Usage: mkdir <directory_name>\n";  // Сообщение о правильном использовании при отсутствии аргументов
    return;
  }

  const std::string& directory_name = args[0];

  try {
    if (std::filesystem::exists(directory_name)) {
      std::cerr << "Error: Directory already exists: " << directory_name << "\n";
    } else {
      std::filesystem::create_directory(directory_name);
      // Сообщение об успешном создании, если необходимо
      // std::cout << "Directory created: " << directory_name << "\n";
    }
  } catch (const std::filesystem::filesystem_error& e) {
    std::cerr << "Error: " << e.what() << "\n";  // Сообщение об ошибке, если каталог не удалось создать
  }
}

void Mkdir::Run() {
//  // Базовый метод, который выводит сообщение о правильном использовании
//  std::cout << "Usage: mkdir <directory_name>\n";
}