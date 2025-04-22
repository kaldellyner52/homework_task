#include "function.h"
#include <iostream>
#include <thread>
#include <chrono>
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
    cout << "\nввед≥ть ≥м'€ громад€нина: ";
    getline(cin, name);

    Person newPerson(name, ticketNumber++);
    queue.push(newPerson);

    cout << "ваш номер у черз≥: [" << newPerson.getTicket() << "] - " << newPerson.getName() << "\n\n";
}

void MREOQueue::callNext() {
    if (queue.empty()) {
        cout << "черга пуста\n\n";
        return;
    }

    Person current = queue.front();
    cout << "номер " << current.getTicket() << ": " << current.getName() << ", п≥д≥йд≥ть до в≥конц€\n";
    cout << "у вас Ї 5 секунд, щоб натиснути enter...\n";

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

    if (responded) {
        cout << current.getName() << " зареЇстровано. номер " << current.getTicket() << " обслуговано\n\n";
    }
    else {
        cout << current.getName() << " не в≥дпов≥в. переходимо до наступного\n\n";
    }

    queue.pop();
}

void MREOQueue::viewQueue() {
    if (queue.empty()) {
        cout << "черга порожн€\n\n";
        return;
    }

    cout << "поточна черга в мрео:\n";
    std::queue<Person> tempQueue = queue;
    while (!tempQueue.empty()) {
        Person current = tempQueue.front();
        cout << "  номер: " << current.getTicket() << " | ≥м'€: " << current.getName() << "\n";
        tempQueue.pop();
    }
    cout << "\n";
}
