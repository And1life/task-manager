#include "../include/ConsoleInterface.hpp"


ConsoleInterface::ConsoleInterface(TaskManager &manager)
    : manager(manager) 
{
}

void ConsoleInterface::run()
{
    printMainMenu();
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