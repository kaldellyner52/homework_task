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
        cout << "мрео симулятор черги\n";
        cout << "==============================\n";
        cout << "1. додати громадянина до черги\n";
        cout << "2. викликати наступного\n";
        cout << "3. переглянути чергу\n";
        cout << "4. вихід\n";
        cout << "ваш вибір: ";

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
            cout << "до побачення! гарного дня\n";
            break;
        }
        else {
            cout << "невірний вибір! спробуйте ще раз\n\n";
        }
    }

    return 0;
}
