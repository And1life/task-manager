#pragma once
#include "Task.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <atomic>
#include <iostream>


class TaskManager
{

public:

    void addTask(const Task& task);
    void removeTask(const std::string& id);
    bool editTask(const std::string& id, const Task& updatedTask);
    Task* getTask(const std::string& id);

    bool startTask(const std::string& id);
    bool pauseTask(const std::string& id);
    bool resumeTask(const std::string& id);
    bool completeTask(const std::string& id);
    bool failTask(const std::string& id);

    void runTasks();
    void stopTasks();

    std::vector<Task> getTasksByStatus(Status status);
    std::vector<Task> getTasksByPriority(Priority priority);
    std::vector<Task> getAllTasks();

    bool saveToFile(const std::string& filename);
    bool loadFromFile(const std::string& filename);

    void sortTasksByPriority();
    void sortTasksByStatus();
    void checkDependencies(const std::string& id);
private:

    std::vector<Task> tasks;
    std::vector<std::thread> threads;
    std::mutex mtx;
    std::atomic<bool> running;

};
