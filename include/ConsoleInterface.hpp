#pragma once

#include "../include/core/TaskManager.hpp"
#include "utils/file_utils.hpp"
#include <iomanip>
#include <cstdlib> 

class ConsoleInterface
{
public:

    explicit ConsoleInterface(TaskManager& manager);

    void run();

private:

    TaskManager& manager;

    void clearConsole() const;
    void printMainMenu() const;
    void printPriorityMenu() const;
    Priority selectPriority();
    void ViewAllTasks() const;
    void handleAddTask();
    void handleRemoveTask();
    void handleEditTask();
    void handleSaveTasks();
    void handleLoadTasks();
};