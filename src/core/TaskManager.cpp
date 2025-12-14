#include "../../include/core/TaskManager.hpp"



void TaskManager::addTask(const Task &task)
{
    std::lock_guard<std::mutex> lock(mtx);

    Task newTask = task;
    if (newTask.Id.empty())
    {
        newTask.Id = generateId();
    }
    

    for (auto &&existingTask : tasks)
    {
        if (existingTask.Id == newTask.Id)
        {
            throw TaskException("Task with ID " + newTask.Id + " already exists.");           
        }       
    }
    
    if (task.name.empty() || task.description.empty())
    {
        throw TaskException("Task name or description can't be empty.");
    }
    
    tasks.push_back(newTask);
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
}

bool TaskManager::editTask(const std::string &id, const Task &updatedTask)
{
    std::lock_guard<std::mutex> lock(mtx);

    bool edited = false;
    for (auto &&task : tasks)
    {
        if (task.Id == id)
        {
            if (!updatedTask.name.empty())
            {
                task.name = updatedTask.name;
                edited = true;
            }
            if (!updatedTask.description.empty())
            {
                task.description = updatedTask.description;
                edited = true;
            }
            if (updatedTask.priority != task.priority)
            {
                task.priority = updatedTask.priority;
                edited = true;
            }
            return edited;            
        }
        
    }
    throw TaskException("Task with ID " + id + " not found.");  
}

std::vector<Task> TaskManager::getAllTasks()
{
    std::lock_guard<std::mutex> lock(mtx);
    return tasks;
}

std::string TaskManager::generateId()
{
    boost::uuids::random_generator gen;
    boost::uuids::uuid uuid = gen();
    return boost::uuids::to_string(uuid).substr(0, 8);
}

std::string TaskManager::priorityToString(Priority priority)
{
    switch (priority)
    {

    case Priority::LOW :        return "Low";
    case Priority::MEDIUM :     return "Medium";
    case Priority::HIGH :       return "High";
    default :                   return "Unknown";        
    
    }
}

std::string TaskManager::statusToString(Status status)
{
    switch (status)
    {

    case Status::PENDING :          return "Pending";
    case Status::RUNNING :          return "Running";
    case Status::PAUSED :           return "Paused";
    case Status::COMPLETED :        return "Completed";
    case Status::FAILED :           return "Failed";
    default :                       return "Unknown";        
    
    }
}
