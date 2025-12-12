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
    "",
    {},
    {},
    {},
    {},
};
    manager.addTask(task1);
    manager.addTask(task2);

    return 0;
}
