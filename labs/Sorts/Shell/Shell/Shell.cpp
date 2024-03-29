// Shell.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    // Начинаем с большого шага и постепенно его уменьшаем
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Применяем сортировку вставками для каждого подмассива с шагом gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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

    shellSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
