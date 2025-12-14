#include "file_utils.hpp"
#include "time_utils.hpp"

bool FileUtils::saveTasksToFile(const std::vector<Task> &tasks, const std::string &filename)
{
    try
    {
        nlohmann::json jsonTasks;

        for (auto &&task : tasks)
        {
            nlohmann::json jsonTask;
            jsonTask["ID"] = task.Id;
            jsonTask["name"] = task.name;
            jsonTask["description"] = task.description;
            jsonTask["priority"] = static_cast<int>(task.priority);
            jsonTask["status"] = static_cast<int>(task.status);

            jsonTask["created_at"] = TimeUtils::timePointToString(task.created_at);

            if (task.start_time.time_since_epoch().count() != 0)
            {
                jsonTask["start_time"] = TimeUtils::timePointToString(task.start_time);
            }

            if (task.end_time.time_since_epoch().count() != 0)
            {
                jsonTask["end_time"] = TimeUtils::timePointToString(task.end_time);
            }
            
            jsonTask["duration"] = task.duration.count();

            jsonTasks.push_back(jsonTask);
        }
        

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}