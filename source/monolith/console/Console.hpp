#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include <stack>
#include <vector>
#include "CommandFactory.hpp"  // Подключаем фабрику команд

class CommandFactory;  // Предварительное объявление класса

class Console {
public:
  // Конструктор, принимающий ссылку на фабрику команд
  explicit Console(CommandFactory& factory);

  // Запуск процесса консоли
  void StartProcess();

  // Основной цикл обработки команд
  void Run(int argc, char** argv);

  // Чтение следующей команды из стандартного ввода
  std::string ReadNextCommandString();

  // Установка состояния работы консоли
  void SetRunning(bool running) { running_ = running; }

  // Проверка состояния работы консоли
  bool IsRunning() const { return running_; }

  // Получение истории команд
  std::stack<std::string> GetHistory() const { return history_; }

  // Получение текущей рабочей директории
  std::string GetWorkingDirectory() const { return working_directory_; }
  void UpdateWorkingDirectory(const std::string& new_directory);

  std::stack<std::string> previous_directories_;

private:
  std::string working_directory_;  // Рабочая директория
  std::stack<std::string> history_; // История команд
  // Добавлен стек
  // Исполнение команды
  void ExecuteCommand(const std::vector<char*>& args);

  bool running_ = true;  // Состояние работы консоли
  CommandFactory& factory_;  // Ссылка на фабрику команд
};

#endif // CONSOLE_HPP
