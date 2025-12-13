#pragma once

#include "../include/core/TaskManager.hpp"
#include <iomanip>

class ConsoleInterface
{
public:

    explicit ConsoleInterface(TaskManager& manager);

    void run();

private:

    TaskManager& manager;

    void printMainMenu() const;
    void ViewAllTasks() const;
    void handleAddTask();
    void handleRemoveTask();
    void handleEditTask();
};