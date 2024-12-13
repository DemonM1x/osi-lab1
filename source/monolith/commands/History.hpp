#ifndef MONOLITH_HISTORY_HPP
#define MONOLITH_HISTORY_HPP
#include "monolith/console/Console.hpp"  // Подключаем консоль для доступа к её методам
#include "monolith/console/Command.hpp"  // Подключаем базовый класс Command

class History : public Command {
public:
  explicit History(Console* console) : Command(console) {
  }                     // Вызов конструктора базового класса
  void Run() override;  // Метод для выполнения команды
  // Реализуем метод Run с аргументом std::vector<std::string>
  void Run(const std::vector<std::string>& args) override;
};

#endif  // MONOLITH_HISTORY_HPP
