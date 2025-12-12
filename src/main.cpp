#include <iostream>
#include "../include/core/Task.hpp"
#include "../include/core/TaskManager.hpp"


int main(int argc, char const *argv[])
{

    TaskManager manager;

Task task1 = {
    "1",
    "Bob",
    "Hello",
    {},
    {},
    {},
    {},
};

Task task2 = {
    "2", 
    "Bob", 
    "Gggg",
    {},
    {},
    {},
    {},
};
    manager.addTask(task1);
    manager.addTask(task2);

    std::vector<Task> allTasks = manager.getAllTasks();
    for (auto &&task : allTasks)
    {
        std::cout << "ID: " << task.Id << "\tName: " << task.name << std::endl;
    }
    

    return 0;
}
