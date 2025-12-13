#include <iostream>
#include "../include/core/TaskManager.hpp"
#include "../include/ConsoleInterface.hpp"


int main(int argc, char const *argv[])
{

    Task task = 
    {
        "1",
        "Clean",
        "clean room"
    };

    Task task2 = 
    {
        "2",
        "Walk",
        "walk in the park"
    };
    TaskManager manager;
    manager.addTask(task);
    manager.addTask(task2);
    ConsoleInterface console(manager);
    console.run();
        

    return 0;
}
