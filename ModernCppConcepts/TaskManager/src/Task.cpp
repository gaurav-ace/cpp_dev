#include "../include/Task.h"

void Task::showTask()
{
    cout << "TaskId\t\t Description\t\t Due In\t\t Priority\t\t Status\n";
    cout << this.taskId << "\t\t " << this.Description << "\t\t " << this.dueInDays << "\t\t " << this.pri
         << "\t\t " << this.taskStatus << "\n";
}