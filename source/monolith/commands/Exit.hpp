#ifndef EXIT_HPP
#define EXIT_HPP

#include "monolith/console/Console.hpp"  // Подключаем консоль для доступа к её методам
#include "monolith/console/Command.hpp"  // Подключаем базовый класс Command

class Exit : public Command {
public:
  explicit Exit(Console* console) : Command(console) {}  // Вызываем конструктор базового класса

  void Run() override;  // Метод для выполнения команды выхода
  void Run(const std::vector<std::string>& args) override;  // Метод с аргументами, игнорирует их

private:
  Console* console_;  // Указатель на объект оболочки
};

#endif // EXIT_HPP
