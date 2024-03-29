// Boyer-Moore.cpp: определяет точку входа для приложения.
//

#include "Boyer-Moore.h"

#include <iostream>
#include <vector>
#include <string>

void precomputeShifts(const std::string& pattern, std::vector<int>& shifts) {
    int m = pattern.length();
    shifts.assign(256, m); // Заполнение вектора смещений значениями по умолчанию
    for (int i = 0; i < m - 1; ++i) {
        shifts[static_cast<unsigned char>(pattern[i])] = m - i - 1; // Записываем смещения для символов из шаблона
    }
}

void boyerMoore(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    std::vector<int> shifts;
    precomputeShifts(pattern, shifts);

    int i = m - 1; // Индекс для текста
    int j = m - 1; // Индекс для шаблона

    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                std::cout << "Найдено вхождение шаблона на позиции " << i << std::endl;
                i += m; // Переходим к следующему возможному вхождению
                j = m - 1;
            }
            else {
                --i;
                --j;
            }
        }
        else {
            i += shifts[static_cast<unsigned char>(text[i])] > m - j ? shifts[static_cast<unsigned char>(text[i])] : m - j;
            j = m - 1; // Возвращаем индекс шаблона в конец
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::string text = "abacadabrabracabracadabrabrabracad";
    std::cout << "Исходная строка: " << text << std::endl;

    std::string pattern = "ab";
    std::cout << "Исходная строка: " << pattern << std::endl;

    boyerMoore(text, pattern);

    return 0;
}
