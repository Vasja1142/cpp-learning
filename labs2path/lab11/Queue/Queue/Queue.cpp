// Queue.cpp: определяет точку входа для приложения.
//

#include "Queue.h"

using namespace std;

struct queue {
    int a[1000];

    //Для более лаконичной реализации работы, мы будем
    //хранить указатель не на последний элемент, а
    //на следующий за ним (несуществующий).

    //Это, в частности, позволит нам проверять очередь на пустоту
    //простым условием head == tail
    int head = 0;    //Индекс первого элемента.
    int tail = 0;    //Индекс элемента, следующего за последним.

    void push(int x) {
        a[tail] = x;
        tail++;
    }

    int pop() {
        if (head != tail) {
            head++;
            return a[head - 1];
        }
        else {
            //Ошибка, попытка извлечь элемент из пустой очереди.
        }
    }

    bool is_empty() {
        return head == tail;
    }
};

int main() {
    queue que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);
    que.push(7);
    que.push(8);
    while (!que.is_empty())
    {
        cout << que.pop() << " ";
    }
    return 0;
}