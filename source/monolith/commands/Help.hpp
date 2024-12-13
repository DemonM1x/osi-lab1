#ifndef HELP_HPP
#define HELP_HPP

#include "monolith/console/Console.hpp"  // Подключаем консоль для доступа к её методам
#include "monolith/console/Command.hpp"  // Подключаем базовый класс Command

class Help : public Command {
public:
  explicit Help(Console* console) : Command(console) {
  }                     // Вызов конструктора базового класса
  void Run() override;  // Метод для выполнения команды
  void Run(const std::vector<std::string>& args) override;  // Метод с аргументами
};

#endif // HELP_HPP
