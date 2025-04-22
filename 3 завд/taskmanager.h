#pragma once
#include "task.h"
#include <vector>
#include <iostream>

class TaskManager {
    std::vector<Task> tasks;
public:
    void addTask(const std::string& desc, int prio);
    void executeTask();
    void changePriority(int index, int newPrio);
    void showTasks() const;
};
