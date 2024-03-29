// Knuth-Morris-Pratt.cpp: определяет точку входа для приложения.
//

#include "Knuth-Morris-Pratt.h"

using namespace std;

#include <iostream>
#include <vector>
#include <string>

// Функция для вычисления префиксной функции для строки
std::vector<int> computePrefixFunction(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> prefix(m);
    prefix[0] = 0;
    int k = 0;

    for (int i = 1; i < m; ++i) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            ++k;
        }
        prefix[i] = k;
    }

    return prefix;
}

// Функция для поиска всех вхождений шаблона в текст с использованием алгоритма Кнута-Морриса-Пратта
void KMP(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    std::vector<int> prefix = computePrefixFunction(pattern);

    int q = 0; // Текущий индекс в тексте

    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            ++q;
        }
        if (q == m) {
            std::cout << "Найдено вхождение шаблона на позиции " << i - m + 1 << std::endl;
            q = prefix[q - 1];
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::string text = "abacadabrabracabracadabrabrabracad";
    std::cout << "Исходная строка: " << text << std::endl;

    std::string pattern = "abracadabra";
    std::cout << "Исходная строка: " << pattern << std::endl;
    KMP(text, pattern);

    return 0;
}

