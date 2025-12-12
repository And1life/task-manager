#pragma once

#include <stdexcept>
#include <string>

class TaskException : public std::runtime_error
{

public:

    explicit TaskException(const std::string& message)
            : std::runtime_error(message)
    {
    
    }

};