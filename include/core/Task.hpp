#pragma once

#include "../../include/utils/TaskException.hpp"
#include <string>
#include <vector>
#include <chrono>

enum class Priority
{
    LOW,
    MEDIUM,
    HIGH,
    UNKNOWN
};

enum class Status
{
    PENDING,
    RUNNING,
    PAUSED,
    COMPLETED,
    FAILED
};

struct Task
{
    std::string Id;
    std::string name;
    std::string description;
    Priority priority;
    Status status;
    std::chrono::system_clock::time_point created_at;
    std::chrono::system_clock::time_point start_time;
    std::chrono::system_clock::time_point end_time;
    std::chrono::milliseconds duration;

};
