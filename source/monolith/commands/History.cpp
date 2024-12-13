#include "History.hpp"
#include <iostream>

void History::Run() {
  if (console_ == nullptr) {
    std::cerr << "Error: Console not initialized.\n";
    return;
  }

  auto history = console_->GetHistory();  // Получаем копию стека с историей команд
  if (history.empty()) {
    std::cout << "History is empty." << std::endl;
    return;
  }

  std::cout << "Command History:" << std::endl;
  int index = 1;
  // Извлекаем команды из стека сверху вниз
  while (!history.empty()) {
    std::cout << index++ << ": " << history.top() << std::endl;
    history.pop();
  }
}


// Реализация метода Run с аргументом std::vector<std::string>
void History::Run(const std::vector<std::string>& args) {
  // Если аргументы не требуются, игнорируем их и выводим историю, как в базовом методе Run()
  if (args.empty()) {
    Run();  // Вызываем метод Run(), если аргументов нет
    return;
  }

  // Если есть аргументы, можно добавить расширенное поведение
  std::cout << "Executing history command with arguments:\n";
  for (const auto& arg : args) {
    std::cout << "Argument: " << arg << "\n";
  }
  // Выводим историю команд после обработки аргументов
  Run();
}
