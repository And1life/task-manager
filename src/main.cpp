#include <iostream>
#include "../include/core/TaskManager.hpp"
#include "../include/ConsoleInterface.hpp"


int main(int argc, char const *argv[])
{

    TaskManager manager;
    ConsoleInterface console(manager);
    console.run();
        

    return 0;
}
