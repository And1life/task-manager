#pragma once

#include "../include/core/TaskManager.hpp"

class ConsoleInterface
{
public:

    explicit ConsoleInterface(TaskManager& manager);

    void run();

private:

    TaskManager& manager;

    void printMainMenu() const;
    void handleViewAllTasks() const;
    void handleAddTask();
    void handleRemoveTask();
    void handleEditTask();
};