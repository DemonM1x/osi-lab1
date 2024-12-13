#include "EmaSortInt.hpp"
#include "EmaSortIntProcess.hpp"
//
// Created by slava on 11.12.2024.
//

#define MAX_VAL 10000000
#define ALPHA_COEF 0.5
EmaSortInt::EmaSortInt(Console* console) : Command(console) {
}
void EmaSortInt::Run() {
  std::cout << "execute ema-sort-int benchmark. ";
}

void EmaSortInt::print_usage() {
  std::cerr << "Usage: " << "ema-sort-int" << " <iterations>" << '\n';
}

void EmaSortInt::Run(const std::vector<std::string>& args) {
  if (args.size() != 1) {
    print_usage();
    return;
  }
  std::vector<int> arr;
  int iterations = std::stoi(args[0]);
  double alpha = ALPHA_COEF;  // Параметр сглаживания, можно настроить
  int random_number = 0;
  for (int i = 1; i <= MAX_VAL; i++) {
    random_number = rand() % MAX_VAL + 1;
    arr.push_back(random_number);
  }
  for (int i = 0; i < iterations; ++i) {
    EmaSortIntProcess::emaSort(arr, alpha);
  }



}