#ifndef CAT_HPP
#define CAT_HPP

#include "monolith/console/Console.hpp"
#include "monolith/console/Command.hpp"
#include <vector>
#include <string>

class Cat : public Command {
public:
  explicit Cat(Console* console) : Command(console) {}

  void Run() override;                           // Метод для выполнения команды без аргументов
  void Run(const std::vector<std::string>& args) override;  // Метод с аргументами
};

#endif // CAT_HPP