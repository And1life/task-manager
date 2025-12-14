#pragma once

#include <string>
#include <vector>
#include <iostream> 
#include "core/Task.hpp"
#include "nlohmann/json.hpp"

class FileUtils
{

public:

    static bool saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename);
    static bool loadTasksFromFile(const std::vector<Task>& tasks, const std::string& filename);

};