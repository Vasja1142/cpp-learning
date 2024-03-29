// SimpleSorts.cpp: определяет точку входа для приложения.
//

#include "SimpleSorts.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void swap(int arr[], int pos1, int pos2) {
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
};

int partition(int arr[], int low, int high, int pivot) {
    int i = low;
    int j = low;
    while (i <= high) {
        if (arr[i] > pivot) {
            i++;
        }
        else {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
};

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
};
void merge(vector<int>& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void naturalMergeSort(vector<int>& arr) {
    bool sorted = false;
    while (!sorted) {
        int p = 0;
        int r = arr.size() - 1;
        sorted = true;
        while (p < r) {
            int q = p;
            while (q < r && arr[q] <= arr[q + 1]) {
                q++;
            }
            if (q < r) {
                merge(arr, p, q, r);
                sorted = false;
            }
            p = q + 1;
        }
    }
}

void countSort(int array[], int size) {
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int output[100];
    int count[100];
    int max = array[0];

    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
};

void bucketSort(int sarray[], int array_size) {
    const int max = 25;
    // use bucket[x][max] to hold the current count
    int bucket[10][max + 1];
    // init bucket counters
    for (int x = 0; x < 10; x++) bucket[x][max] = 0;
    // main loop for each digit position
    for (int digit = 1; digit <= 1000000000; digit *= 10) {
        // array to bucket
        for (int i = 0; i < max; i++) {
            // get the digit 0-9
            int dig = (sarray[i] / digit) % 10;
            // add to bucket and increment count
            bucket[dig][bucket[dig][max]++] = sarray[i];
        }
        // bucket to array
        int idx = 0;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < bucket[x][max]; y++) {
                sarray[idx++] = bucket[x][y];
            }
            // reset the internal bucket counters
            bucket[x][max] = 0;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(0));

    int n = 25;
    vector<int> arr(n);
    int* arr2 = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = getRandomNumber(1, 100);
        arr2[i] = arr[i];
    }


    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Введите номер сортировки:";
    int num;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "Сортировка слиянием\n";
        naturalMergeSort(arr);
        cout << "Отсортированный массив: ";
        for (int num : arr) {
            cout << num << " ";
        }
        break;
    case 2:
        cout << "Быстрая сортировка\n";
        quickSort(arr2, 0, size(arr) - 1);
        cout << "Отсортированный массив: ";

        for (int i = 0; i < size(arr); i++) {
            cout << arr2[i] << " ";
        }
        break;
    case 3:
        cout << "Сортировка подсчетом\n";
        countSort(arr2, n);
        cout << "Отсортированный массив: ";
        for (int i = 0; i < n; i++) {
            cout << arr2[i] << " ";
        }
        break;
    case 4:
        cout << "Блочная сортировка\n";
        bucketSort(arr2, n);
        cout << "Отсортированный массив: ";
        for (int i = 0; i < n; i++) {
            cout << arr2[i] << " ";
        }
        break;

        
    default:
        break;
    }
    return 0;
}
