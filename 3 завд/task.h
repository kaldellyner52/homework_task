#pragma once
#include <string>

struct Task {
    std::string description;
    int priority;

    Task(std::string desc, int prio);
};
