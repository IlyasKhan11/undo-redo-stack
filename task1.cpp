#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    stack<string> history;

public:
    void addText(const string& newText) {
        history.push(text);
        text += newText;
        cout << "Added text: \"" << newText << "\"\n";
    }

    void deleteText(int count) {
        if (count > text.size()) {
            cout << "Cannot delete more characters than present.\n";
            return;
        }
        history.push(text);
        text.erase(text.size() - count);
        cout << "Deleted last " << count << " characters\n";
    }

    void undo() {
        if (!history.empty()) {
            text = history.top();
            history.pop();
            cout << "Undo performed. Current text: \"" << text << "\"\n";
        } else {
            cout << "No operations to undo.\n";
        }
    }

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
