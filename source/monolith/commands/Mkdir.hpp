//
// Created by eliza on 01.11.2024.
//

#ifndef MONOLITH_MKDIR_HPP
#define MONOLITH_MKDIR_HPP
#include "monolith/console/Console.hpp"  // Подключаем консоль для доступа к её методам
#include "monolith/console/Command.hpp"  // Подключаем базовый класс Command
#include <string>
#include <vector>

class Mkdir : public Command {
public:
  explicit Mkdir(Console* console) : Command(console) {}  // Конструктор с привязкой к консоли
  void Run() override;  // Выводит инструкцию по использованию команды
  void Run(const std::vector<std::string>& args) override;  // Создает каталог с указанным именем
};


#endif  // MONOLITH_MKDIR_HPP
