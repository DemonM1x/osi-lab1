//
// Created by slava on 11.12.2024.
//

#ifndef MONOLITH_EMASORTINT_HPP
#define MONOLITH_EMASORTINT_HPP


#include "../console/Command.hpp"
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

class EmaSortInt : public Command {
public:
  explicit EmaSortInt(Console* console);

  void Run() override;                           // Метод для выполнения команды без аргументов
  void Run(const std::vector<std::string>& args) override;  // Метод с аргументами
  void print_usage();
};


#endif  // MONOLITH_EMASORTINT_HPP
