#include <iostream>

using namespace std;
#include "../include/TaskManager.h"

int main()
{
    char action;
    int dueIn, id;
    std::string desc;
    int priority;

    cout << "Setting up the cmake environment for TaskManager project...\n";

    cout << "Done...\n";

    cout <<  "#########################################\n"
         <<  "#\t\t            \t\t#\n"
         <<  "#\t\tTask Manager\t\t#\n"
         <<  "#\t\t            \t\t#\n"
         <<  "#########################################\n";

    cout << "Please choose an action for taskmanager : \n"
         << "A - Add task\n"
         << "M - Mark Completed\n"
         << "G - Get task details by Id\n"
         << "S - Show task List\n";
    
    cin >> action;

    TaskManager tm = TaskManager();

    switch(action)
    {
        case 'A': cout << "Please provide task details : description, due in days and priority \n";
                 cin >> desc >> dueIn >> priority;
                 
                 Priority pri;
                 switch(priority) {
                    case 0 : pri = Priority::LOW;
                             break;
                    case 1 : pri = Priority::MEDIUM;
                             break;
                    case 2 : pri = Priority::HIGH;
                              break;
                    default : cout << "invalid priority\n";
                                break; 
                 }
                 tm.addTask(Task(desc, dueIn, pri));
                 break;
        
        case 'M' : cout << "Enter the task Id to be marked as completed : \n";
                 cin >> id;
                 tm.markCompleted(id);
                 break;
        
        case 'G' : cout << "Enter the task Id : \n";
                 cin >> id;
                 Task t = tm.getTask(id);
                 t.showTask();
                 break;
        
        case 'S' : cout << "Task List : \n";
                 for (auto t : tm.getTaskList())
                 {
                    t.show();
                 }
                 
        default : break;
    }

    return 0;
}