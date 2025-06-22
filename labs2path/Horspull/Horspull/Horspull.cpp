// Horspull.cpp: определяет точку входа для приложения.
//

#include "Horspull.h"

using namespace std;


string str = "METADATA";
string str2 = "DATA*";
int len = size(str2) - 1;
int arr[] = { 4,1,2,1,5 };


bool check(int val) {
	bool flag = true;
	for (size_t i = 0; i < len; i++)
	{
		if (str[len + val] != str2[len])
		{
			flag = false;
		}
	}
}

int shift() {

}

int search() {
	int result = 0;
	int val = 0;
	if (check(val))
		result++;
	else
	{
		
	}
};

int main()
{
	cout << str << endl;
	cout << str2 << endl;



}
