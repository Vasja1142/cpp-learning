// 7.	Структура "Студент":
//-фамилия, имя, отчество;
//-домашний адрес;
//-группа;
//-рейтинг.
//Удалить все элементы, у которых рейтинг меньше заданного, добавить 1 элемент в конец файла.
//

#include "lab8.h"
#include <fstream>

using namespace std;
std::ofstream fout;

class Student
{
public:
	string firstName;
	string lastName;
	string patronumic;
	string addres;
	string group;
	int rating;
	Student(string firstName, 
			string lastName,
			string patronumic,
			string addres,
			string group,
			int rating):
				firstName{ firstName },
				lastName{ lastName },
				patronumic{patronumic},
				addres{ addres },
				group{ group },
				rating{ rating }
			{}
	void writeStudent() {
		fout.open("Students.txt", ios::app);
		fout << firstName << "/" << lastName << "/" << patronumic << "/";
		fout << addres << "/" << group << "/" << rating << endl;
		fout.close();
	}

};

int main()
{
	
	Student Dima{ "Дима", "Петров", "Алексеевич", "Пермь", "РИС", 23 };
	Student Sasha{ "Саша", "Сидоров", "Александрович", "Кудымкар", "РИС", 48 };
	Student Dasha{ "Даша", "Иванова", "Витальевна", "Пермь", "РИС", 21 };
	if (Dima.rating < 30) {
		Dima.writeStudent();
	}
	if (Sasha.rating < 30) {
		Sasha.writeStudent();
	}
	if (Dasha.rating < 30) {
		Dasha.writeStudent();
	}
	


	return 0;
}
