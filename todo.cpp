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
        for (const auto& task : tasks) {
            file << task.description << "|" << task.completed << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        tasks.clear();
        ifstream file(filename);
        string desc;
        bool comp;
        while (file >> ws && getline(file, desc, '|') && file >> comp) {
            tasks.emplace_back(desc, comp);
        }
        file.close();
    }

public:
    ToDoList() { loadFromFile(); }

    void addTask(const string& desc) {
        tasks.emplace_back(desc);
        saveToFile();
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            saveToFile();
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void markCompleted(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            saveToFile();
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void showTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] " << tasks[i].description << endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    string desc;
    int index;

    while (true) {
        cout << "\n1. Add Task\n2. Remove Task\n3. Mark Completed\n4. Show Tasks\n5. Exit\nEnter choice: ";
        cin >> choice;
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
            todo.showTasks();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}
