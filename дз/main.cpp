#include <iostream>
#include "function.h"
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<vector<int>> matrix;
    vector<int> vval, vpos, vptz;
    int rows = 0, cols = 0;

    cout << "Оберіть спосіб заповнення матриці:\n1 - Випадково\n2 - Вручну\nВаш вибір: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        fillMatrixRandom(matrix, rows, cols);
        break;
    case 2:
        fillMatrixUser(matrix, rows, cols);
        break;
    default:
        cout << "Невірний вибір!" << endl;
        return 1;
    }

    displayMatrix(matrix);
    convertToCSR(matrix, vval, vpos, vptz);
    displayCSR(vval, vpos, vptz);

    int scalar;
    cout << "\nВведіть число для віднімання з діагоналі: ";
    cin >> scalar;

    subtractScalarFromDiagonal(vval, vpos, vptz, scalar, rows);
    restoreMatrixFromCSR(matrix, vval, vpos, vptz);

    displayMatrix(matrix);
    displayCSR(vval, vpos, vptz);

    return 0;
}
