#pragma once

#include <string>
#include <vector>
#include "../core/Task.hpp"

class FileUtils
{

public:

    static bool saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename);
    static bool loadTasksFromFile(const std::vector<Task>& tasks, const std::string& filename);

};