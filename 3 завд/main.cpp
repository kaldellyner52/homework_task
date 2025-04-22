#include "taskmanager.h"
#include <iostream>
#include <Windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TaskManager manager;
    int choice;

    std::cout << "вітаю у менеджері завдань!\n";

    while (true) {
        std::cout << "\n1.додати завдання\n2.виконати перше завдання\n3.змінити пріоритет\n4.показати всі завдання\n5.вийти\nваш вибір: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore();
            std::string desc;
            int prio;
            std::cout << "введіть текст завдання: ";
            std::getline(std::cin, desc);
            std::cout << "введіть пріоритетність завдання: ";
            std::cin >> prio;
            manager.addTask(desc, prio);
            std::cout << "завдання додано!\n";
        }
        else if (choice == 2) {
            manager.executeTask();
        }
        else if (choice == 3) {
            int index, newPrio;
            std::cout << "введіть індекс завдання: ";
            std::cin >> index;
            std::cout << "новий пріоритет: ";
            std::cin >> newPrio;
            manager.changePriority(index, newPrio);
        }
        else if (choice == 4) {
            manager.showTasks();
        }
        else if (choice == 5) {
            std::cout << "\nдо зустрічі!\n";
            break;
        }
        else {
            std::cout << "\nневірний вибір! спробуйте знову.\n";
        }
    }

    return 0;
}
