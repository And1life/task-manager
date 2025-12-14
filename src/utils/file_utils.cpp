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
        
        std::ofstream file(filename);
        if (!file.is_open())
        {
            return false;
        }

        file << jsonTasks.dump(4);
        file.close();

        return true;

    }
    catch(const std::exception& e)
    {
        return false;
    }
    
}

bool FileUtils::loadTasksFromFile(std::vector<Task> &tasks, const std::string &filename)
{
    try
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return false;
        }

        nlohmann::json jsonTasks;
        file >> jsonTasks;
        file.close();

        for (auto && jsonTask : jsonTasks)
        {
            Task task;
            task.Id = jsonTask["ID"];
            task.name = jsonTask["name"];
            task.description = jsonTask["description"];
            task.priority = static_cast<Priority>(jsonTask["priority"].get<int>());
            task.status = static_cast<Status>(jsonTask["status"].get<int>());

            task.created_at = TimeUtils::stringToTimePoint(jsonTask["created_at"]);

            if (jsonTask.contains("start_time"))
            {
                task.start_time = TimeUtils::stringToTimePoint(jsonTask["start_time"]);
            }
            
            if (jsonTask.contains("end_time"))
            {
                task.end_time = TimeUtils::stringToTimePoint(jsonTask["end_time"]);
            }

            task.duration = std::chrono::milliseconds(jsonTask["duration"].get<int64_t>());

            tasks.push_back(task);
        }
        
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    
}
