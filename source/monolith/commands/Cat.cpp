#include "Cat.hpp"
#include <iostream>
#include <fstream>

// Реализация метода Run без аргументов
void Cat::Run() {
//  std::cout << "Cat command requires at least one file name as an argument.\n";
}

// Реализация метода Run с аргументом std::vector<std::string>
void Cat::Run(const std::vector<std::string>& args) {
  if (args.empty()) {
    Run();  // Если нет аргументов, вызовем версию без аргументов
    return;
  }

  for (const auto& filename : args) {
    std::ifstream file(filename);
    if (!file) {
      std::cerr << "Error: Unable to open file " << filename << "\n";
      continue;
    }

    std::cout << "Contents of " << filename << ":\n";
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << "\n";
    }
    std::cout << "---- End of " << filename << " ----\n";
  }
}
