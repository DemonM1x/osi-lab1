#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <vector>
#include <string>
#include <memory>

class Console;  // Вперёд-объявление, чтобы избежать циклической зависимости

// Базовый класс для команд
class Command {
protected:
  Console* console_;  // Указатель на консоль, к которой привязана команда

public:
  Command() = default;  // Конструктор по умолчанию
  // Конструктор для привязки команды к консоли
  Command(Console* console) : console_(console) {}

  virtual void Run() = 0;  // Метод для выполнения команды
  virtual void BindToShell(Console* console) { console_ = console; }  // Связываем с консолью

  virtual ~Command() = default;  // Деструктор по умолчанию
  virtual void Run(const std::vector<std::string>& args) = 0;
};

#endif // COMMAND_HPP

