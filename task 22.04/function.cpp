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
    cout << "\n������ ��'� �����������: ";
    getline(cin, name);

    Person newPerson(name, ticketNumber++);
    queue.push(newPerson);

    cout << "��� ����� � ����: [" << newPerson.getTicket() << "] - " << newPerson.getName() << "\n\n";
}

void MREOQueue::callNext() {
    if (queue.empty()) {
        cout << "����� �����\n\n";
        return;
    }

    Person current = queue.front();
    cout << "����� " << current.getTicket() << ": " << current.getName() << ", ������ �� ������\n";
    cout << "� ��� � 5 ������, ��� ��������� enter...\n";

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
        cout << current.getName() << " ������������. ����� " << current.getTicket() << " �����������\n\n";
    }
    else {
        cout << current.getName() << " �� ������. ���������� �� ����������\n\n";
    }

    queue.pop();
}

void MREOQueue::viewQueue() {
    if (queue.empty()) {
        cout << "����� �������\n\n";
        return;
    }

    cout << "������� ����� � ����:\n";
    std::queue<Person> tempQueue = queue;
    while (!tempQueue.empty()) {
        Person current = tempQueue.front();
        cout << "  �����: " << current.getTicket() << " | ��'�: " << current.getName() << "\n";
        tempQueue.pop();
    }
    cout << "\n";
}
