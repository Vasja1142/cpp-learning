// Fibonacci.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int fibonacci(int a, int b, int count) {
	if (count == 0)
	{
		return a;
	}
	else
	{
		return fibonacci(b, a + b, --count);
	}
}

int main()
{
	int m = 6;
	std::cout << fibonacci(1, 1, m-1);
}
