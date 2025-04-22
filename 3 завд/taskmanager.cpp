#include "taskmanager.h"

void TaskManager::addTask(const std::string& desc, int prio) {
    Task newTask(desc, prio);
    int pos = 0;
    while (pos < tasks.size() && tasks[pos].priority >= prio) ++pos;
    tasks.insert(tasks.begin() + pos, newTask);
}

void TaskManager::executeTask() {
    if (tasks.empty()) {
        std::cout << "\nзавдань немає!\n";
        return;
    }
    std::cout << "\nвиконано завдання: " << tasks.front().description << "\n";
    tasks.erase(tasks.begin());
}

void TaskManager::changePriority(int index, int newPrio) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "\nневірний індекс!\n";
        return;
    }
    Task temp = tasks[index];
    tasks.erase(tasks.begin() + index);
    temp.priority = newPrio;
    addTask(temp.description, temp.priority);
    std::cout << "\nпріоритет змінено!\n";
}

void TaskManager::showTasks() const {
    if (tasks.empty()) {
        std::cout << "\nсписок завдань порожній.\n";
        return;
    }
    std::cout << "\nсписок завдань:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i << ". [пріоритет: " << tasks[i].priority << "] " << tasks[i].description << "\n";
    }
}