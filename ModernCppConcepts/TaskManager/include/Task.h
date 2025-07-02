#ifndef TASK_H
#define TASK_H

#include <string>

enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

enum class TaskStatus {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
};

class Task {
public :
    Task() {}

    void showTask();

private :
    int taskId;
    std::string description;
    int dueInDays;
    Priority pri;
    TaskStatus taskStatus;
};

#endif // TASK_H