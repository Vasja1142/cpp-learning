// HanoiTower.cpp: определяет точку входа для приложения.
//


#include <iostream>
#include <fstream>


   



using namespace std;
ofstream out;
ofstream pout;
int x1;
int x2;
int x3;
int counter;

void calcHanoi(int from, int to) {
    switch (from) {
    case 1:
        x1--;
        break;
    case 2:
        x2--;
        break;
    case 3:
        x3--;
        break;
    }
    switch (to)
    {
    case 1:
        x1++;
        break;
    case 2:
        x2++;
        break;
    case 3:
        x3++;
        break;
    }
  
}

void printHanoi() {
    pout << "Итерация - " << ++counter << endl;
    for (size_t i = 0; i < x1; i++)
    {
        pout << '|';
    }
    pout << endl;

    for (size_t i = 0; i < x2; i++)
    {
        pout << '|';
    }
    pout << endl;

    for (size_t i = 0; i < x3; i++)
    {
        pout << '|';
    }
    pout << endl << "===================\n";

}

void hanoi_towers(int quantity, int from, int to, int buf_peg)  //quantity-число колец, from-начальное положение колец(1-3),to-конечное положение колец(1-3)
{                               //buf_peg - промежуточный колышек(1-3)
    if (quantity != 0)
    {
        hanoi_towers(quantity - 1, from, buf_peg, to);

        if (out.is_open())
        {
            calcHanoi(from, to);
            printHanoi();
            out << from << " -> " << to << endl;

        }

        hanoi_towers(quantity - 1, buf_peg, to, from);
    }
}




int main()
{
    setlocale(LC_ALL, "rus");
    int start_peg = 1;
    int destination_peg = 3; 
    int buffer_peg = 2;
    int plate_quantity;
    cout << "Количество дисков:" << endl;
    cin >> plate_quantity;

    x1 = plate_quantity;
    x2 = 0;
    x3 = 0;
    pout.open("HanoiTower2.txt");
    out.open("HanoiTower1.txt");     
    
    printHanoi();
    hanoi_towers(plate_quantity, start_peg, destination_peg, buffer_peg);
    pout.close();
    out.close();
    std::cout << "File has been written" << std::endl;

    return 0;
}
