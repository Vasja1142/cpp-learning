// Haar.cpp: определяет точку входа для приложения.
//

#include "Haar.h"
#include <iostream>
#include <vector>

// Функция слияния двух отсортированных подмассивов
void merge(std::vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Функция сортировки Хаара
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2]; // Выбираем опорный элемент
        int i = low;
        int j = high;

        // Разделение массива на две части
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // Рекурсивные вызовы для двух частей массива
        quickSort(arr, low, j);
        quickSort(arr, i, high);
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<int> arr = { 12, 34, 54, 2, 3 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

