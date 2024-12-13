#ifndef LS_HPP
#define LS_HPP

#include "monolith/console/Command.hpp"
#include <vector>
#include <string>
#include <filesystem>

class Ls : public Command {
public:
  // Объявляем конструктор, но не определяем его здесь
  Ls(Console* console);

  void Run() override;
  void Run(const std::vector<std::string>& args) override;
};

#endif // LS_HPP
