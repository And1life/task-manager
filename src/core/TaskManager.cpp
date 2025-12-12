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
}

void TaskManager::removeTask(const std::string &id)
{
    std::lock_guard<std::mutex> lock(mtx);

    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&id](const Task& task) {return task.Id == id; });

    if (it == tasks.end())
    {
        throw TaskException("Task with ID " + id + " not found.");
    }
    
    tasks.erase(it);
    std::cout << "Task removed: ID = " << id << std::endl;
}
std::vector<Task> TaskManager::getAllTasks()
{
    std::lock_guard<std::mutex> lock(mtx);
    return tasks;
}