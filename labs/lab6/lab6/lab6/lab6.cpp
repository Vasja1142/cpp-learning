// Преобразовать строку так, чтобы все буквы в ней были отсортированы по возрастанию.
//

#include "lab6.h"

using namespace std;

int main()
{
	string str = "hello world!";
	cout << str << endl;
	char minChar;
	string minCharS;
	int minIndex;
	string res;
	for (size_t i = 0; i < size(str)-1; i++)
	{
		minChar = str[i];
		minIndex = i;
		for (size_t j = i+1; j < size(str); j++)
		{
			if (minChar > str[j])
			{
				minChar = str[j];
				minIndex = j;
			}
		}
		str.erase(minIndex, 1);
		minCharS = minChar;
		str.insert(i, minCharS);
	}
	cout << str;
	return 0;
}
