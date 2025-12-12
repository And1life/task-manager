#include "../../include/core/TaskManager.hpp"

void TaskManager::addTask(const Task &task)
{
    std::lock_guard<std::mutex> lock(mtx);

    for (auto &&existingTask : tasks)
    {
        if (existingTask.Id == task.Id)
        {
            throw TaskException("Task with ID " + task.Id + " already exists.");           
        }       
    }
    
    if (task.name.empty() || task.description.empty())
    {
        throw TaskException("Task name or description can't be empty.");
    }
    
    tasks.push_back(task);

    std::cout << "Done.\n";
}