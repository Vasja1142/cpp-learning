// lab9.cpp: определяет точку входа для приложения.




#include "lab9.h"
#include <fstream>
#include <string>

using namespace std;
ofstream fout;
ifstream fin;
ofstream rout;
ifstream rin;

void createFail() {
	fout.open("F1.txt");// окрываем файл для чтения-записи
	string text = "Мороз и солнце; день чудесный!\n"
		"Еще ты дремлешь, друг прелестный —\n"
		"Пора, красавица, проснись:\n"
		"Открой сомкнуты негой взоры\n"
		"Навстречу северной Авроры,\n"
		"Звездою севера явись!\n\n"

		"Вечор, ты помнишь, вьюга злилась,\n"
		"На мутном небе мгла носилась;\n"
		"Луна, как бледное пятно,\n"
		"Сквозь тучи мрачные желтела,\n"
		"И ты печальная сидела —\n"
		"А нынче… погляди в окно :\n\n"

		"Под голубыми небесами\n"
		"Великолепными коврами,\n"
		"Блестя на солнце, снег лежит;\n"
		"Прозрачный лес один чернеет,\n"
		"И ель сквозь иней зеленеет,\n"
		"И речка подо льдом блестит.\n\n"

		"Вся комната янтарным блеском\n"
		"Озарена.Веселым треском\n"
		"Трещит затопленная печь.\n"
		"Приятно думать у лежанки.\n"
		"Но знаешь : не велеть ли в санки\n"
		"Кобылку бурую запречь ?\n\n"

		"Скользя по утреннему снегу,\n"
		"Друг милый, предадимся бегу\n"
		"Нетерпеливого коня\n"
		"И навестим поля пустые, \n"
		"Леса, недавно столь густые,\n"
		"И берег, милый для меня.\n";
		fout << text;
		fout.close();
}

void createFali2() {
	fin.open("F1.txt");
	rout.open("F2.txt");
	string line;
	while (getline(fin, line))
	{
		if (line[0] != 'А')
		{
			rout << line << endl;
		}
	}
	rout.close();
	fin.close();
}

int lenFirstWord() {
	rin.open("F2.txt");
	string line;
	getline(rin, line);
	int res = 0;
	for (size_t i = 0; line[i] != ' '; i++)
	{
		res++;
	}
	rin.close();
	return res;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	createFail();
	createFali2();
	cout << "Количество символов первого слова: " << lenFirstWord();
	
	return 0;
}