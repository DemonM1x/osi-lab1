//
// Created by slava on 11.12.2024.
//

#ifndef MONOLITH_DEDUP_HPP
#define MONOLITH_DEDUP_HPP
#include "monolith/console/Command.hpp"
#include <set>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
class Dedup : public Command {
public:
  explicit Dedup(Console* console);

  void print_usage();
  void dedup(std::vector<int>& arr);
  void Run() override;                           // Метод для выполнения команды без аргументов
  void Run(const std::vector<std::string>& args) override;  // Метод с аргументами

};

#endif  // MONOLITH_DEDUP_HPP
