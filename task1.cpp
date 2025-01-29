#include <iostream>
#include <stack>
#include <string>

class TextEditor {
private:
    std::string text; // Holds the current text
    std::stack<std::string> history; // Tracks states for undo operations

public:
    // Add new text to the editor if it's non-empty
    void addText(const std::string& newText) {
        if (newText.empty()) {
            std::cout << "No text to add.\n";
            return;
        }
        history.push(text);
        text += newText;
        std::cout << "Added text: \"" << newText << "\"\n";
    }

    // Delete the last 'count' characters if valid
    void deleteText(int count) {
        if (count <= 0) {
            std::cout << "Invalid count. Count must be positive.\n";
            return;
        }
        if (count > text.size()) {
            std::cout << "Cannot delete more characters than present.\n";
            return;
        }
        history.push(text);
        text.erase(text.size() - count);
        std::cout << "Deleted last " << count << " characters\n";
    }

    // Revert to the previous state if possible
    void undo() {
        if (!history.empty()) {
            text = history.top();
            history.pop();
            std::cout << "Undo performed. Current text: \"" << text << "\"\n";
        } else {
            std::cout << "No operations to undo.\n";
        }
    }

    // Display the current text
    void displayText() const {
        std::cout << "Current text: \"" << text << "\"\n";
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

    // Additional test cases
    editor.addText(""); // Test adding empty text
    editor.deleteText(-3); // Test invalid negative count
    editor.deleteText(3); // Test valid deletion
    editor.displayText();

    return 0;
}