#include "function.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MREOQueue mreo;
    string choice;

    while (true) {
        cout << "==============================\n";
        cout << "���� ��������� �����\n";
        cout << "==============================\n";
        cout << "1. ������ ����������� �� �����\n";
        cout << "2. ��������� ����������\n";
        cout << "3. ����������� �����\n";
        cout << "4. �����\n";
        cout << "��� ����: ";

        getline(cin, choice);
        cout << "\n";

        if (choice == "1") {
            mreo.addPerson();
        }
        else if (choice == "2") {
            mreo.callNext();
        }
        else if (choice == "3") {
            mreo.viewQueue();
        }
        else if (choice == "4") {
            cout << "�� ���������! ������� ���\n";
            break;
        }
        else {
            cout << "������� ����! ��������� �� ���\n\n";
        }
    }

    return 0;
}
