// lab11.cpp: определяет точку входа для приложения.
//1.	Написать функцию для создания списка. Функция может создавать пустой список, а затем добавлять в него элементы.
//2.	Написать функцию для печати списка.Функция должна предусматривать вывод сообщения, если список пустой.
//3.	Написать функции для удаления и добавления элементов списка в соответствии со своим вариантом.
//4.	Выполнить изменения в списке и печать списка после каждого изменения.
//5.	Написать функцию для записи списка в файл.
//6.	Написать функцию для уничтожения списка.
//7.	Записать список в файл, уничтожить его и выполнить печать(при печати должно быть выдано сообщение "Список пустой").
//8.	Написать функцию для восстановления списка из файла.
//9.	Восстановить список и распечатать его.
//10.	Уничтожить список.
//	Сформировать двунаправленный список.Удалить из него первый элемент, добавить элемент в конец списка.


#include "lab11.h"
#include <fstream>
#include <string>

using namespace std;
ofstream fout;

struct DoubleList //описание узла списка
{
	int data; //информационное поле
	DoubleList* next; //указатель на следующий элемент
	DoubleList* prev; //указатель на предыдущий элемент
};
DoubleList* head; //указатель на первый элемент списка

//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************
void AddDoubleList(int value, int position)
{

	DoubleList* node = new DoubleList; //создание нового элемента
	node->data = value; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		node->next = node; //установка указателя next
		node->prev = node; //установка указателя prev
		head = node; //определяется голова списка
	}
	else
	{
		DoubleList* p = head;

		for (int i = 0; i < position; i++) p = p->next;

		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
}

//******************ДОБАВЛЕНИЕ СПИСКА ИЗ ФАЙЛА*******************
void AddDoubleListFromFile()
{
	ifstream fin("DoubleLists.txt");
	if (fin.is_open())
	{
		int counter = 0;
		int x;
		while (fin >> x)
		{
			AddDoubleList(x, counter++);
		}
	}

	cout << "\nСписок добавлен из файла...\n\n";
}

//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************
int DeleteDoubleNode(int position)
{
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList* a = head;
		for (int i = position; i > 1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	cout << "\nЭлемент удален...\n\n";
}


//***********************УДАЛЕНИЕ СПИСКА***********************
int DeleteDoubleList()
{
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	while (head != head->next)
	{
		DoubleList* a = head;
		head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}

	delete head;
	head = NULL;

	cout << "\nСписок удален...\n\n";
}

//*******************ЗАПИСЬ СПИСКА В ФАЙЛ**********************
void PrintListFromFile()
{
	fout.open("DoubleLists.txt");
	if (head == NULL) {
		fout << "\nСписок пуст\n\n";
	}

	else
	{
		DoubleList* a = head;
		do
		{
			fout << a->data << " ";
			a = a->next;
		} while (a != head);
		fout << "\n\n";
	}
	fout.close();
}

//*************************ВЫВОД СПИСКА*************************
void PrintDoubleList()
{
	if (head == NULL) { 
		cout << "\nСписок пуст\n\n";
	}

	else
	{
		DoubleList* a = head;
		cout << "\nЭлементы списка: ";
		do
		{
			cout << a->data << " ";
			a = a->next;
		} while (a != head); 
		cout << "\n\n";
	}
}
//************************ГЛАВНАЯ ФУНКЦИЯ************************
void main()
{
	setlocale(LC_ALL, "Rus");

	AddDoubleList(0, 0);
	PrintDoubleList();
	AddDoubleList(1, 1);
	PrintDoubleList();
	AddDoubleList(2, 2); 
	PrintDoubleList();
	AddDoubleList(3, 3);
	PrintDoubleList();
	DeleteDoubleNode(0);
	PrintListFromFile();
	PrintDoubleList();
	DeleteDoubleList();
	PrintDoubleList();
	AddDoubleListFromFile();
	PrintDoubleList();
	/*do
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести список" << endl;
		cout << "0. Выйти" << endl;
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			cout << "Позиция > "; cin >> position;
			AddList(value, position); break;
		case 2:
			cout << "Позиция > "; cin >> position;
			DeleteList(position); break;
		case 3: PrintList(); break;
		}
	} while (x != 0);*/
}


