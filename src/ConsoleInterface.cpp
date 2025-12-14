#include "../include/ConsoleInterface.hpp"



ConsoleInterface::ConsoleInterface(TaskManager &manager)
    : manager(manager) 
{
}

void ConsoleInterface::run()
{
    while (true)
    {
        clearConsole();
        printMainMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clearConsole();

        switch (choice)
        {
        case 1:
            ViewAllTasks();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cerr << "Invalid choice. Try again." << std::endl;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


void ConsoleInterface::clearConsole() const
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
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
void ConsoleInterface::handleAddTask()
{
}

void ConsoleInterface::handleRemoveTask()
{
}

void ConsoleInterface::handleEditTask()
{
}
