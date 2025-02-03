#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc, bool comp = false) : description(desc), completed(comp) {}
};

class ToDoList {
private:
    vector<Task> tasks;
    const string filename = "tasks.txt";

    void saveToFile() {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }
        for (const auto& task : tasks) {
            file << task.description << "|" << boolalpha << task.completed << "\n";
        }
    }

    void loadFromFile() {
        tasks.clear();
        ifstream file(filename);
        if (!file) return;

        string desc;
        bool comp;
        while (file >> ws && getline(file, desc, '|') && file >> boolalpha >> comp) {
            tasks.emplace_back(desc, comp);
        }
    }

public:
    ToDoList() { loadFromFile(); }

    void addTask(const string& desc) {
        if (desc.empty()) {
            cout << "Task description cannot be empty.\n";
            return;
        }
        tasks.emplace_back(desc);
        saveToFile();
        cout << "Task added successfully!\n";
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        saveToFile();
        cout << "Task removed successfully!\n";
    }

    void markCompleted(int index, bool completed = true) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }
        tasks[index - 1].completed = completed;
        saveToFile();
        cout << "Task marked as " << (completed ? "completed" : "incomplete") << "!\n";
    }

    void showTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "\nTo-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] " << tasks[i].description << "\n";
        }
    }
};

int main() {
    ToDoList todo;
    int choice, index;
    string desc;

    while (true) {
        cout << "\n1. Add Task\n2. Remove Task\n3. Mark Completed\n4. Mark Incomplete\n5. Show Tasks\n6. Exit\nEnter choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, desc);
                todo.addTask(desc);
                break;
            case 2:
                cout << "Enter task number to remove: ";
                cin >> index;
                todo.removeTask(index);
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                todo.markCompleted(index);
                break;
            case 4:
                cout << "Enter task number to mark as incomplete: ";
                cin >> index;
                todo.markCompleted(index, false);
                break;
            case 5:
                todo.showTasks();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
