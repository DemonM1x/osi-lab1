#include "Command.hpp"
#include <cstring>
#include <sstream>
#include <vector>

// Разбиение строки на токены
std::vector<std::string> split_line(const std::string &line) {
  std::vector<std::string> tokens;
  std::istringstream stream(line);
  std::string token;

  while (stream >> token) {
    tokens.push_back(token);
  }

  return tokens;
}
