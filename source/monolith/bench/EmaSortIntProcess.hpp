//
// Created by slava on 11.12.2024.
//

#ifndef MONOLITH_EMASORTINTPROCESS_HPP
#define MONOLITH_EMASORTINTPROCESS_HPP
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

class EmaSortIntProcess {
  public:
    static double calculateEMA(double current, double previous, double alpha);
    static void emaSort(std::vector<int>& arr, double alpha);
};
#endif  // MONOLITH_EMASORTINTPROCESS_HPP
