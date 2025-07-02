#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "Task.h"

enum class Status {
    FAIL,
    PASS
}

class Task;

class TaskManager {
public:
    TaskManager() {}

    // add task
    Status addTask(Task t);

    // mark completed
    Status markCompleted(int Id);

    // get Due days
    Task getTask(int id);

    // get task list
    std::vector<Task> TaskManager::getTaskList();
private: 
std::vector<Task> taskList;
};

#endif // TASKMANAGER_H