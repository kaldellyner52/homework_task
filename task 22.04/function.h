#pragma once
#include <queue>
#include <string>

class Person {
public:
    Person(const std::string& name, int ticket);
    std::string getName() const;
    int getTicket() const;

private:
    std::string name;
    int ticket;
};

class MREOQueue {
public:
    void addPerson();
    void callNext();
    void viewQueue();

private:
    int ticketNumber = 1;
    std::queue<Person> queue;
};
