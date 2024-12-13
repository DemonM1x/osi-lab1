#include "CommandFactory.hpp"

#include <iostream>

#include "Console.hpp"
#include "monolith/commands/Cat.hpp"
#include "monolith/commands/Cd.hpp"
#include "monolith/commands/Exit.hpp"
#include "monolith/commands/Help.hpp"
#include "monolith/commands/History.hpp"
#include "monolith/commands/Ls.hpp"
#include "monolith/commands/Mkdir.hpp"
#include "monolith/commands/Rm.hpp"
#include "monolith/bench/EmaSortInt.hpp"
#include "monolith/bench/Dedup.hpp"

// Конструктор класса CommandFactory
CommandFactory::CommandFactory(Console* console) : console_(console) {
  RegisterCommands();  // Регистрация команд
}

// Метод для регистрации команд
void CommandFactory::RegisterCommands() {
  // Регистрация команды ls
  command_map_["ls"] = [this](std::vector<std::string> args) {
    return std::make_unique<Ls>(console_);
  };

  // Регистрация команды history
  command_map_["history"] = [this](std::vector<std::string> args) {
    return std::make_unique<History>(console_);
  };

  // Регистрация команды help
  command_map_["help"] = [this](std::vector<std::string> args) {
    return std::make_unique<Help>(console_);
  };

  // Регистрация команды exit
  command_map_["exit"] = [this](std::vector<std::string> args) {
    return std::make_unique<Exit>(console_);
  };

  // Регистрация команды cat
  command_map_["cat"] = [this](std::vector<std::string> args) {
    return std::make_unique<Cat>(console_);
  };

  // Регистрация команды cd
  command_map_["cd"] = [this](std::vector<std::string> args) {
    return std::make_unique<Cd>(console_);
  };

  // Регистрация команды mkdir
  command_map_["mkdir"] = [this](std::vector<std::string> args) {
    return std::make_unique<Mkdir>(console_);
  };

  // Регистрация команды rm
  command_map_["rm"] = [this](std::vector<std::string> args) {
    return std::make_unique<Rm>(console_);
  };

  // Регистрация команды ema-sort-int
  command_map_["ema-sort-int"] = [this](std::vector<std::string> args) {
    return std::make_unique<EmaSortInt>(console_);
  };

  // Регистрация команды bin
  command_map_["dedup"] = [this](std::vector<std::string> args) {
    return std::make_unique<Dedup>(console_);
  };
}


// Метод для создания команд
std::unique_ptr<Command> CommandFactory::CreateCommand(const std::string& command_name, std::vector<std::string> args) {
  auto it = command_map_.find(command_name);
  if (it != command_map_.end()) {
    return it->second(args);  // Создает и возвращает команду с аргументами
  }
  return nullptr;  // Если команда не найдена
}
void CommandFactory::SetConsole(Console* console) {
  console_ = console;  // Устанавливаем указатель на объект консоли
}