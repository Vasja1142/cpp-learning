// Sorts.cpp: определяет точку входа для приложения.
//

#include "Sorts.h"

using namespace std;
string text = "Hello";

void method(int c) {
	text += " world!";
	cout << c;
};

int main()
{
	int num = 3;

	num <<= 1;

	int* r = &num;

	cout << r << endl;
	cout << num << endl;

	
	cout << &text << endl;
	cout << text << endl;

	char a = text[2];
	char* rt = &a;
	cout << rt << endl;
	cout << *rt << endl;

	long arr[] = {2, 4, 3};
	long* ra = &arr[0];
	ra += 1;
	cout << *ra << endl;
	void(&rf)(int) = method;
	rf(32);
	cout << text;
	return 0;
}
