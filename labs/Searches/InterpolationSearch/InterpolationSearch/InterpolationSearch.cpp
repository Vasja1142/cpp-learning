// InterpolationSearch.cpp: определяет точку входа для приложения.
//

#include "InterpolationSearch.h"

#include <iostream>
#include <vector>

// Функция для интерполяционного поиска элемента в отсортированном массиве
int interpolationSearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Используем формулу интерполяции для оценки местоположения целевого элемента
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Если целевой элемент найден
        if (arr[pos] == target) {
            return pos;
        }

        // Если целевой элемент меньше значения в pos, сужаем диапазон до левой половины
        if (arr[pos] > target) {
            high = pos - 1;
        }

        // Если целевой элемент больше значения в pos, сужаем диапазон до правой половины
        else {
            low = pos + 1;
        }
    }

    // Если элемент не найден, возвращаем -1
    return -1;
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<int> arr = { 2, 3, 12, 34, 54 };
    int target = 12;

    std::cout << "Массив: ";
    for each (int var in arr)
    {
        std::cout << var << " ";
    }
    std::cout << "\nЗначение: " << target << std::endl;

    int index = interpolationSearch(arr, target);
    if (index != -1) {
        std::cout << "Элемент " << target << " найден по индексу " << index << std::endl;
    }
    else {
        std::cout << "Элемент " << target << " не найден в массиве" << std::endl;
    }

    return 0;
}
