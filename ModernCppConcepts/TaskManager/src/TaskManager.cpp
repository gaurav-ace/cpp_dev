#include "../include/TaskManager.h"

Status TaskManager::addTask(Task t)
{
    std::vector<Task> tList = getTaskList();
    tList.push_back(t);
    return Status::PASS;
}

Status TaskManager::markCompleted(int Id)
{ 
    Task t = getTask(Id);
    t.taskStatus = TaskStatus::COMPLETED;
    return Status::PASS;
}

Task TaskManager::getTask(int id)
{
    std::vector<Task> tList = getTaskList();
    for(auto t : tList)
    {
        if(t.taskId == id)
            return t;
    }
    return Task();
}

std::vector<Task> TaskManager::getTaskList()
{
    return taskList;
}


