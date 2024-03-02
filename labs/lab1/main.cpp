#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    const int n = 5;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) { a[i][j] = 0; }
            else a[i][j] = i - j + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


