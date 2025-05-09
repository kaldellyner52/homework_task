#include "function.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <Windows.h>

using namespace std;

Person::Person(const string& name, int ticket)
    : name(name), ticket(ticket) {
}

string Person::getName() const {
    return name;
}

int Person::getTicket() const {
    return ticket;
}

void MREOQueue::addPerson() {
    string name;
    cout << "\nвведіть ім'я громадянина: ";
    getline(cin, name);

    Person newPerson(name, ticketNumber++);
    queue.push(newPerson);

    cout << "ваш номер у черзі: [" << newPerson.getTicket() << "] - " << newPerson.getName() << "\n\n";
}

void MREOQueue::callNext() {
    if (queue.empty()) {
        cout << "черга пуста\n\n";
        return;
    }

    Person current = queue.front();
    cout << "номер " << current.getTicket() << ": " << current.getName() << ", підійдіть до віконця\n";
    cout << "у вас є 5 секунд, щоб натиснути enter...\n";

    string input;
    bool responded = false;

    thread inputThread([&]() {
        getline(cin, input);
        responded = true;
        });

    for (int i = 0; i < 50; ++i) {
        if (responded) break;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    if (inputThread.joinable()) {
        inputThread.detach();
    }

    ofstream file;
    if (responded) {
        cout << current.getName() << " зареєстровано. номер " << current.getTicket() << " обслуговано\n\n";
        file.open("served.txt", ios::app);
        file << "Обслуговано: " << current.getTicket() << " - " << current.getName() << "\n";
    }
    else {
        cout << current.getName() << " не відповів. переходимо до наступного\n\n";
        file.open("missed.txt", ios::app);
        file << "Не з'явився: " << current.getTicket() << " - " << current.getName() << "\n";
    }
    file.close();

    queue.pop();
}

void MREOQueue::viewQueue() {
    if (queue.empty()) {
        cout << "черга порожня\n\n";
        return;
    }

    cout << "поточна черга в мрео:\n";
    std::queue<Person> tempQueue = queue;
    while (!tempQueue.empty()) {
        Person current = tempQueue.front();
        cout << "  номер: " << current.getTicket() << " | ім'я: " << current.getName() << "\n";
        tempQueue.pop();
    }
    cout << "\n";
}
