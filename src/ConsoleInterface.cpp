#include "../include/ConsoleInterface.hpp"



ConsoleInterface::ConsoleInterface(TaskManager &manager)
    : manager(manager) 
{
}

void ConsoleInterface::run()
{
    while (true)
    {
        clearConsole();
        printMainMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clearConsole();

        switch (choice)
        {
        case 1:
            ViewAllTasks();
            break;
        case 2:
            handleAddTask();
            break;
        case 3:
            handleRemoveTask();
            break;
        case 4:
            handleEditTask();
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cerr << "Invalid choice. Try again." << std::endl;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


void ConsoleInterface::clearConsole() const
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void ConsoleInterface::printMainMenu() const
{
    std::cout << "\n=== Task Manager ===" << std::endl;
    std::cout << "1. View all tasks" << std::endl;
    std::cout << "2. Add new task" << std::endl;
    std::cout << "3. Remove a task" << std::endl;
    std::cout << "4. Edit a tasks" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void ConsoleInterface::printPriorityMenu() const
{
    std::cout << "\n=== Select Priority ===" << std::endl;
    std::cout << "1. Low" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. High" << std::endl;
    std::cout << "Enter your choice: ";
}

Priority ConsoleInterface::selectPriority()
{
    while (true)
    {
        printPriorityMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1: return Priority::LOW;
        case 2: return Priority::MEDIUM;
        case 3: return Priority::HIGH;
        default:
            std::cerr << "invalid choice. Try again." << std::endl;
        }
    }
}

void ConsoleInterface::ViewAllTasks() const
{
    std::vector<Task> tasks = manager.getAllTasks();

    if (tasks.empty())
    {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(20) << "Name"
              << std::setw(30) << "Description"
              << std::setw(15) << "Priority"
              << std::setw(15) << "Status"
              << std::endl;

    std::cout << std::string(80, '-') << std::endl;

    for (auto &&task : tasks)
    {
        std::cout << std::left << std::setw(10) << task.Id
                  << std::setw(20) << task.name
                  << std::setw(30) << task.description
                  << std::setw(15) << TaskManager::priorityToString(task.priority)
                  << std::setw(15) << TaskManager::statusToString(task.status)
                  << std::endl;
    }
}
void ConsoleInterface::handleAddTask()
{
    clearConsole();
    std::string name, description;
    std::cout << "Enter task name: ";
    std::getline(std::cin, name);
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);

    Task newTask
    {
        {},
        name,
        description,
        Priority::MEDIUM,
        Status::PENDING,
        std::chrono::system_clock::now(),
        {},
        {},
        {}
    };

    try
    {
        manager.addTask(newTask);
        std::cout << "Task added successfully!" << std::endl;
    }
    catch(const TaskException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
}

void ConsoleInterface::handleRemoveTask()
{
    clearConsole();
    ViewAllTasks();

    if (manager.getAllTasks().empty())
    {
        return;
    }
      
    std::string id;
    std::cout << "Enter task ID to remove: ";
    std::getline(std::cin, id);

    try
    {
        manager.removeTask(id);
        std::cout << "Task removed successfully!" << std::endl;
    }
    catch(const TaskException& e)
    {
        std::cerr << "Error:" << e.what() << std::endl;
    }
}

void ConsoleInterface::handleEditTask()
{
    clearConsole();
    ViewAllTasks();
    
    if (manager.getAllTasks().empty())
    {
        return;
    }
    
    std::cout << "\n=== Edit Task ===" << std::endl;
    std::string id;
    std::cout << "Enter task ID to edit: ";
    std::getline(std::cin, id);

    try
    {
        clearConsole();
        Task currentTask;
        bool taskFound = false;
        for (auto &&task : manager.getAllTasks())
        {
            if (task.Id == id)
            {
                currentTask = task;
                taskFound = true;
                break;
            }  
        }
        
        if (!taskFound)
        {
            std::cerr << "Task not found." << std::endl;
            return;
        }

        std::cout << "\nCurrent task details:" << std::endl;
        std::cout << "Name: " << currentTask.name << std::endl;
        std::cout << "Description: " << currentTask.description << std::endl;
        std::cout << "Priority: " << TaskManager::priorityToString(currentTask.priority) << std::endl;
        std::cout << "Status: " << TaskManager::statusToString(currentTask.status) << std::endl;


        std::string newName, newDescription;
        Priority newPriority = currentTask.priority;

        std::cout << "\nEnter new task name (leave empty to skip): ";
        std::getline(std::cin, newName);

        std::cout << "Enter new description (leave empty to skip): ";
        std::getline(std::cin, newDescription);

        std::cout << "Edit priority? (y/n):";
        std::string editPriority;
        std::getline(std::cin, editPriority);
        if (editPriority == "y" || editPriority == "Y")
        {
            newPriority = selectPriority();
        }
        
        Task updatedTask = currentTask;
        updatedTask.name = newName;
        updatedTask.description = newDescription;
        updatedTask.priority = newPriority;


            if (manager.editTask(id, updatedTask))
            {
                std::cout << "\nTask edited successfully!" << std::endl;
            } else 
            {
                std::cout << "\nTask no changes made." << std::endl;
            }    
    }
    catch(const TaskException& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void  ConsoleInterface::handleSaveTasks()
{
    clearConsole();
    std::cout << "=== Save Tasks to File ===" << std::endl;
    std::string filename;
    std::cout << "Enter filename (tasks.json): ";
    std::getline(std::cin, filename);

    try
    {
        if (manager.saveToFile(filename))
        {
            std::cout << "Tasks saved successfully to " << filename << "!" << std::endl;
        }
        else
        {
            std::cerr << "Failed to save tasks." << std::endl;
        }  
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
}

void  ConsoleInterface::handleLoadTasks()
{
    clearConsole();
    std::cout << "=== Load Tasks from File ===" << std::endl;

    std::string filename;
    std::cout << "Enter filename (tasks.json): ";
    std::getline(std::cin, filename);

    try
    {
        if (manager.loadFromFile(filename))
        {
            std::cout << "Tasks loaded successfully from " << filename << "!" << std::endl;
        }
        else
        {
            std::cerr << "Failed to load tasks." << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
}
