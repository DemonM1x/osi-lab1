#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "Command.hpp"

class CommandFactory {
public:
  CommandFactory(Console* console);  // Конструктор с указателем на консоль
  void SetConsole(Console* console); // Метод установки консоли
  std::unique_ptr<Command> CreateCommand(const std::string& command_name, std::vector<std::string> args);

private:
  Console* console_;  // Указатель на объект консоли
  std::unordered_map<std::string, std::function<std::unique_ptr<Command>(std::vector<std::string>)>> command_map_;

  void RegisterCommands();  // Регистрация всех доступных команд
};

#endif // COMMAND_FACTORY_HPP
