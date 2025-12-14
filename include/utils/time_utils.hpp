#pragma once

#include <chrono>
#include <string>

class TimeUtils
{

public:

    static std::string timePointToString(const std::chrono::system_clock::time_point& timePoint);

    static std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);

    static int64_t timePointToMillis(const std::chrono::system_clock::time_point& timePoint);

    static std::chrono::system_clock::time_point millisToTimePoint(int64_t millis);
};