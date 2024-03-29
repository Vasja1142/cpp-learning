// LinearSearch.cpp: определяет точку входа для приложения.
//

#include "LinearSearch.h"

#include <iostream>
#include <vector>

// Функция для линейного поиска элемента в массиве
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Возвращаем индекс найденного элемента
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<int> arr = { 12, 34, 54, 2, 3 };
    int target = 2;
    std::cout << "Массив: ";
    for each (int var in arr)
    {
        std::cout << var << " ";
    }
    std::cout << "\nЗначение: "<< target << std::endl;

    int index = linearSearch(arr, target);
    if (index != -1) {
        std::cout << "Элемент " << target << " найден по индексу " << index << std::endl;
    }
    else {
        std::cout << "Элемент " << target << " не найден в массиве" << std::endl;
    }

    return 0;
}

