// LIst.cpp: определяет точку входа для приложения.
//
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next_ptr;
};

template <class T>
struct Stack
{
	Node<T>* head;
	int size;
};

template <class T>
void SetNode(Node<T>*& node, T data = T(), Node<T>* next_ptr = nullptr) {
	node = new Node<T>();
	node->next_ptr = next_ptr;
	node->data = data;
};

template <class T>
void SetStack(Stack<T>& tmp) {
	tmp.head = nullptr;
	tmp.size = 0;
};

template<class T>
void Push(Stack<T>& tmp, const T& data) {
	Node<T>* new_node;

	SetNode(new_node, data, tmp.head);

	tmp.head = new_node;
	tmp.size++;
};

template<class T>
void Pop(Stack<T>& tmp) {
	if (tmp.head != nullptr) {
		Node<T>* delete_element = tmp.head;
		tmp.head = tmp.head->next_ptr;
		delete delete_element;
		tmp.size--;
	}
};

template<class T>
void print(Stack<T>& tmp) {
	int p = tmp.size;
	if (p == 0)
	{
		cout << "стек пуст";
	}
	else {
		for (size_t i = 0; i < p; i++)
		{
			cout << tmp.head->data << " ";
			Pop(tmp);
		}
	}
};

int main() {
	Stack<int> stack;
	SetStack(stack);

	Push(stack, 2);
	Push(stack, 4);
	Push(stack, 3);
	Pop(stack);
	Push(stack, 1);
	print(stack);
}