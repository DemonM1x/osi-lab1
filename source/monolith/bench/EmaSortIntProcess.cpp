//
// Created by slava on 11.12.2024.
//
#include "EmaSortIntProcess.hpp"

// Функция для вычисления экспоненциального сглаживания (EMA)
double EmaSortIntProcess::calculateEMA(double current, double previous, double alpha) {
  return alpha * current + (1 - alpha) * previous;
}

// Основная функция для сортировки с использованием алгоритма EMA
void EmaSortIntProcess::emaSort(std::vector<int>& arr, double alpha) {
  bool swapped;
  int n = arr.size();

  // Повторяем пока не будет сделано ни одной перестановки
  do {
    swapped = false;

    // Проходим по всем элементам массива
    for (int i = 1; i < n; i++) {
      double emaCurrent = calculateEMA(arr[i], arr[i - 1], alpha);

      // Если текущее значение больше предыдущего по EMA метрике, меняем их местами
      if (arr[i] < arr[i - 1] && emaCurrent < arr[i]) {
        std::swap(arr[i], arr[i - 1]);
        swapped = true;
      }
    }

    n--;  // С каждым проходом можно исключать последний элемент, так как он уже отсортирован

  } while (swapped);  // Продолжаем, если была сделана хотя бы одна перестановка
}