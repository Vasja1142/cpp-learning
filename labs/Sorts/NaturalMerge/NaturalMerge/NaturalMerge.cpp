// NaturalMerge.cpp: определяет точку входа для приложения.
//

#include "NaturalMerge.h"

#include <iostream>
#include <vector>

// Функция для объединения двух отсортированных подпоследовательностей
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

// Функция сортировки естественного слияния
void naturalMergeSort(std::vector<int>& arr) {
    int n = arr.size();

    std::vector<int> tempArr(n); // Временный массив для слияния

    // Ищем подпоследовательности и объединяем их
    while (true) {
        int low = 0;
        while (low < n) {
            int mid = low;
            while (mid + 1 < n && arr[mid] <= arr[mid + 1]) {
                mid++;
            }
            if (mid == n - 1) {
                break; // Если последовательность упорядочена, завершаем
            }
            int high = mid + 1;
            while (high + 1 < n && arr[high] <= arr[high + 1]) {
                high++;
            }
            merge(arr, low, mid, high);// Объединяем две подпоследовательности
            for (int num : arr) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            low = high + 1; // Переходим к следующей паре подпоследовательностей
        }
        if (low == 0) {
            break; // Если не было объединений, значит, массив уже отсортирован
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<int> arr = { 12, 34, 54, 2, 3, 4, 3, 53, 23, 52, 84, 1, 13 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    naturalMergeSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

