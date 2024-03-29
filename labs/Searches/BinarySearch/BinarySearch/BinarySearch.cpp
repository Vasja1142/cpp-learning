// BinarySearch.cpp: определяет точку входа для приложения.
//

#include "BinarySearch.h"

#include <iostream>
#include <vector>

// Функция для бинарного поиска элемента в отсортированном массиве
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Если значение в середине массива равно целевому, возвращаем индекс
        if (arr[mid] == target) {
            return mid;
        }

        // Если значение в середине массива больше целевого, сужаем диапазон до левой половины
        else if (arr[mid] > target) {
            right = mid - 1;
        }

        // Если значение в середине массива меньше целевого, сужаем диапазон до правой половины
        else {
            left = mid + 1;
        }
    }

    // Если элемент не найден, возвращаем -1
    return -1;
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<int> arr = { 2, 3, 12, 34, 54 };
    int target = 54;

    std::cout << "Массив: ";
    for each (int var in arr)
    {
        std::cout << var << " ";
    }
    std::cout << "\nЗначение: " << target << std::endl;

    int index = binarySearch(arr, target);
    if (index != -1) {
        std::cout << "Элемент " << target << " найден по индексу " << index << std::endl;
    }
    else {
        std::cout << "Элемент " << target << " не найден в массиве" << std::endl;
    }

    return 0;
}
