#include "../include/ConsoleInterface.hpp"


ConsoleInterface::ConsoleInterface(TaskManager &manager)
    : manager(manager) 
{
}

void ConsoleInterface::run()
{
    // printMainMenu();
    ViewAllTasks();
}
void ConsoleInterface::printMainMenu() const
{
    std::cout << "\n=== Task Manager ===" << std::endl;
    std::cout << "1. View all tasks" << std::endl;
    std::cout << "2. Add new task" << std::endl;
    std::cout << "3. Remove a task" << std::endl;
    std::cout << "4. Edit a tasks" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void ConsoleInterface::ViewAllTasks() const
{
    std::vector<Task> tasks = manager.getAllTasks();

    if (tasks.empty())
    {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(20) << "Name"
              << std::setw(30) << "Description"
              << std::setw(15) << "Priority"
              << std::setw(15) << "Status"
              << std::endl;

    std::cout << std::string(80, '-') << std::endl;

    for (auto &&task : tasks)
    {
        std::cout << std::left << std::setw(10) << task.Id
                  << std::setw(20) << task.name
                  << std::setw(30) << task.description
                  << std::setw(15) << TaskManager::priorityToString(task.priority)
                  << std::setw(15) << TaskManager::statusToString(task.status)
                  << std::endl;
    }   
}