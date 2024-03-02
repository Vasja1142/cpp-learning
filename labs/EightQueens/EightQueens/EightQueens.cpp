// EightQueens.cpp: определяет точку входа для приложения.
//

#include <fstream>
#include <iostream>

const int SIZE = 8; // Размер.

int board[SIZE][SIZE];
int results_count = 0; // Количество решений.
std::ofstream fout;        // поток для чтения-записи


// Функция showBoard() - отображает доску.
void showBoard()
{
    for (int a = 0; a < SIZE; ++a)
    {
        for (int b = 0; b < SIZE; ++b)
        {
            fout << ((board[a][b]) ? "Q " : ". ");
        }
        fout << "\n";
    }
}

// Функция tryQueen() - проверяет нет ли уже установленных ферзей,
// по вертикали, диагоналям.
bool tryQueen(int a, int b)
{
    for (int i = 0; i < a; ++i)
    {
        if (board[i][b])
        {
            return false;
        }
    }

    for (int i = 1; i <= a && b - i >= 0; ++i)
    {
        if (board[a - i][b - i])
        {
            return false;
        }
    }

    for (int i = 1; i <= a && b + i < SIZE; i++)
    {
        if (board[a - i][b + i])
        {
            return false;
        }
    }

    return true;
}

// Функция setQueen() - пробует найти результаты решений.
void setQueen(int a) // a - номер очередной строки в которую нужно поставить очередного ферзя.
{
    if (a == SIZE)
    {
        showBoard();
        fout << "Result #" << ++results_count << "\n\n";
        return; // Опционально.
    }

    for (int i = 0; i < SIZE; ++i)
    {
        // Здесь проверяем, что если поставим в board[a][i] ферзя (единицу),
        // то он будет единственным в этой строке, столбце и диагоналях.
        if (tryQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a + 1);
            board[a][i] = 0;
        }
    }

    return; // Опционально.
}

int main()
{
    fout.open("EightQueens.txt"); // окрываем файл для чтения-записи
    setQueen(0);
    fout.close();
    return 0;
}