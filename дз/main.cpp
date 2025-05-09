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

    cout << "������ ����� ���������� �������:\n1 - ���������\n2 - ������\n��� ����: ";
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
        cout << "������� ����!" << endl;
        return 1;
    }

    displayMatrix(matrix);
    convertToCSR(matrix, vval, vpos, vptz);
    displayCSR(vval, vpos, vptz);

    int scalar;
    cout << "\n������ ����� ��� �������� � �������: ";
    cin >> scalar;

    subtractScalarFromDiagonal(vval, vpos, vptz, scalar, rows);
    restoreMatrixFromCSR(matrix, vval, vpos, vptz);

    displayMatrix(matrix);
    displayCSR(vval, vpos, vptz);

    return 0;
}
