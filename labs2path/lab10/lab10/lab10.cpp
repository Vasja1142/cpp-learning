// lab10.cpp: определяет точку входа для приложения.


#include "lab10.h"
#include <ctime>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Ru");
    srand(time(0));
    int start = 10;
    int end = 100;
    int x;

    const int rows = 5, columns = 6;
    int** numbers{ new int* [rows] {} };  // выделяем память под двухмерный массив

    // выделяем память для вложенных массивов
    for (int i = 0; i < rows; i++)
    {
        numbers[i] = new int[columns] {};
    }
    cout << "Первый двумерный массив:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            x = rand() % (end - start + 1) + start;
            numbers[i][j] = x;
            cout << numbers[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    int** numbers2{ new int* [rows] {} };  // выделяем память под двухмерный массив

    // выделяем память для вложенных массивов
    for (int i = 0; i < rows; i++)
    {
        numbers2[i] = new int[columns-1] {};
    }

    int deleteIndexColumn = 4;

    cout << "\nВторой двумерный массив:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < deleteIndexColumn; j++)
        {
            numbers2[i][j] = numbers[i][j];
            
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = deleteIndexColumn; j < columns-1; j++)
        {
            numbers2[i][j] = numbers[i][j+1];
        }
    }
   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns - 1; j++)
        {
            cout << numbers2[i][j] << "\t";
        }
        cout << endl;
    }



    // удаление массивов    
    for (int i = 0; i < rows; i++)
    {
        delete[] numbers2[i];
        delete[] numbers[i];
    }
    delete[] numbers;
    delete[] numbers2;
	return 0;
}
