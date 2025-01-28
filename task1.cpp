#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string text; // Holds the current text
    stack<string> history; // Holds the history for undo operations

public:
    // Add new text to the editor
    void addText(const string& newText) {
        history.push(text); // Save current state to history
        text += newText;
        cout << "Added text: \"" << newText << "\"\n";
    }

    // Delete the last 'count' characters
    void deleteText(int count) {
        if (count > text.size()) {
            cout << "Cannot delete more characters than present.\n";
            return;
        }
        history.push(text); // Save current state to history
        text.erase(text.size() - count);
        cout << "Deleted last " << count << " characters\n";
    }

    // Undo the last operation
    void undo() {
        if (!history.empty()) {
            text = history.top(); // Revert to the last saved state
            history.pop();
            cout << "Undo performed. Current text: \"" << text << "\"\n";
        } else {
            cout << "No operations to undo.\n";
        }
    }

    // Display the current text
    void displayText() const {
        cout << "Current text: \"" << text << "\"\n";
    }
};

int main() {
    TextEditor editor;

    editor.addText("Hello");
    editor.displayText();

    editor.addText(" World");
    editor.displayText();

    editor.deleteText(5);
    editor.displayText();

    editor.undo();
    editor.displayText();

    editor.undo();
    editor.displayText();

    editor.undo();
    editor.displayText();

    return 0;
}
