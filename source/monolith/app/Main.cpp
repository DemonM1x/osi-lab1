#include <iostream>

#include "monolith/console/Console.hpp"

namespace monolith::app {
void Main(int argc, char* argv[]) {
  std::cout << "Number of arguments: " << argc << "\n";
  for (int i = 0; i < argc; ++i) {
    std::cout << "argv[" << i << "]: " << argv[i] << "\n";
  }
  CommandFactory factory(nullptr);  // Создаём фабрику команд (null пока что, если не требуется передавать указатель на Console)
  Console console(factory);         // Передаём фабрику команд в конструктор Console
  factory.SetConsole(&console);
  console.Run(argc, argv);           // Запускаем процесс
  }
}  // namespace monolith::app

int main(int argc, char* argv[]) {
  monolith::app::Main(argc, argv);
}