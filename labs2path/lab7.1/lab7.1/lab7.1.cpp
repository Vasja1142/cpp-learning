// Написать перегруженные функции и основную программу, которая их вызывает.
//25.
//а) для двумерного массива удаляет все четные строки;
//б) для одномерного массива удаляет все элементы, заключенные между двумя нулевыми элементами.

#include <iostream>
#include "lab7.1.h"

using namespace std;

void function(const int);
void function();

int main() {
	setlocale(LC_ALL, "Ru");
	int x = 8;

	function(x);
	return 0;
}


void function(int len) {

	int* arr = new int[len];

	int start = 0;
	int end = 3;
	int num;

	cout << "Матрица:\n";
	for (size_t i = 0; i < len; i++)
	{
		num = rand() % (end - start + 1) + start;
		arr[i] = num;
		cout << arr[i] << "  ";
	}

	cout << endl;

	for (size_t i = 0; i < len - 2; i++)
	{
		if (arr[i] == 0 && arr[i + 2] == 0) {
			arr[i + 1] = -1;
		}
	}


	int counter = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] == -1) {
			for (size_t j = i+1; j < len; j++)
			{
				arr[j - 1] = arr[j];
			}
			counter++;
		}
	}

	for (size_t i = 0; i < len - counter; i++)
	{
		cout << arr[i] << "  ";
	}

	
}


void function()
{
	const int length = 6;
	const int height = 7;

	int start = 10;
	int end = 100;
	int num;

	int matrix[length][height];


	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < length; j++) {
			num = rand() % (end - start + 1) + start;
			matrix[j][i] = num;
		}
	}

	cout << "Матрица:\n";
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < length; j++) {
			cout << matrix[j][i]  << "\t";
		}
		cout << endl;
	}

	const int newHeight = height / 2 + height % 2;
	int newMatrix[length][newHeight];

	cout << "Новая матрица:\n";
	int index = 0;

	for (size_t i = 0; i < height; i += 2)
	{
		for (size_t j = 0; j < length; j++) {
			num = rand() % (end - start + 1) + start;
			newMatrix[j][index] = matrix[j][i];
		}
		index++;
	}

	for (size_t i = 0; i < newHeight; i++)
	{
		for (size_t j = 0; j < length; j++) {
			cout << newMatrix[j][i] << "\t";
		}
		cout << endl;
	}
	
}
