#include "../../include/utils/time_utils.hpp"

std::string TimeUtils::timePointToString(const std::chrono::system_clock::time_point &timePoint)
{
    auto time = std::chrono::system_clock::to_time_t(timePoint);
    std::tm tm = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%a %b %d %H:%M:%S %Y");
    return oss.str();
}

std::chrono::system_clock::time_point TimeUtils::stringToTimePoint(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream iss(timeStr);
    iss >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int64_t TimeUtils::timePointToMillis(const std::chrono::system_clock::time_point& timePoint) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        timePoint.time_since_epoch()
    ).count();
}

std::chrono::system_clock::time_point TimeUtils::millisToTimePoint(int64_t millis) {
    return std::chrono::system_clock::time_point(
        std::chrono::milliseconds(millis)
    );
}