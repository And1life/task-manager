#include <iostream>
#include "../include/core/TaskManager.hpp"
#include "../include/ConsoleInterface.hpp"
#include "nlohmann/json.hpp"


int main(int argc, char const *argv[])
{

    // TaskManager manager;
    // ConsoleInterface console(manager);
    // console.run();

    nlohmann::json testJson = {{"test", "value"}};
    std::cout << testJson.dump() << std::endl;


    return 0;
}
