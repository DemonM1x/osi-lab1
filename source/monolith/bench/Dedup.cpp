//
// Created by slava on 11.12.2024.
//

#include "Dedup.hpp"


#define MAX_VAL 10000000
#define DUP_NUM 10

Dedup::Dedup(Console* console) : Command(console) {
}

void Dedup::print_usage(){
  std::cerr << "Usage: " << "dedup" << " <iterations>" << '\n';
}

void Dedup::dedup(std::vector<int>& arr){
  std::set<int> uniqueElements;

  for (int num : arr) {
    uniqueElements.insert(num);
  }

  arr.clear();
  for (int num : uniqueElements) {
    arr.push_back(num);
  }
}

void Dedup::Run(){
  std::cout << "execute dedup benchmark. ";
}
void Dedup::Run(const std::vector<std::string>& args){
  if (args.size() != 1) {
    print_usage();
    return;
  }
  std::vector<int> arr;
  int iterations = std::stoi(args[0]);
  int random_number = 0;

  for (int i = 0; i < iterations; ++i) {
    for (int j = 1; j <= MAX_VAL; ++j) {
      random_number = rand() % DUP_NUM;
      arr.push_back(random_number);
    }
    dedup(arr);
    arr.clear();
  }
}

