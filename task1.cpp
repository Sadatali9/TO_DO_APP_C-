#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

vector<Task> tasks;

void displayMenu() {
    cout << "To-Do List Application" << endl;
    cout << "---------------------" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Mark Task as Completed" << endl;
    cout << "3. View Tasks" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask() {
    Task task;
    cout << "Enter task description: ";
    getline(cin, task.description);
    task.isCompleted = false;
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

void markTaskAsCompleted() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "Current Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i].description << " - " << (tasks[i].isCompleted ? "Completed" : "Not Completed") << endl;
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markTaskAsCompleted();
                break;
            case 3:
                viewTasks();
                break;
            case 4:
                cout << "Exiting application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
