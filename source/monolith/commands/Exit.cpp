#include "Exit.hpp"
#include <iostream>

void Exit::Run() {
  if (this->console_ == nullptr) {
    std::cout << "This command requires a shell to run." << std::endl;
    return;
  }

  std::cout << "Exiting shell..." << std::endl;

  // Устанавливаем флаг завершения работы оболочки
  console_->SetRunning(false);
}

// Реализация метода Run с аргументом std::vector<std::string>
void Exit::Run(const std::vector<std::string>& /* args */) {
  Run();  // Просто вызываем перегруженную версию без аргументов
}
