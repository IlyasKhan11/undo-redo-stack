#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) { // Constructor
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head; // Pointer to the head node

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Update a node's value
    bool update(int oldValue, int newValue) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                return true;
            }
            temp = temp->next;
        }
        return false; // Value not found
    }

    // Delete a node by value
    bool deleteNode(int value) {
        if (head == nullptr) return false;

        Node* temp = head;

        // If head is the node to be deleted
        if (temp->data == value) {
            head = temp->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return true;
        }

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) return false; // Value not found

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
        return true;
    }

    // Display the doubly linked list forward
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display the doubly linked list backward
    void displayBackward() {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp->next != nullptr) { // Move to the last node
            temp = temp->next;
        }

        while (temp != nullptr) { // Traverse backward
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

// Driver code
int main() {
    DoublyLinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Doubly Linked List (Forward): ";
    list.displayForward();

    // Update a node
    if (list.update(20, 25)) 
        cout << "Updated 20 to 25\n";
    else 
        cout << "Value not found\n";
    
    cout << "Doubly Linked List after update (Forward): ";
    list.displayForward();

    // Delete a node
    if (list.deleteNode(30)) 
        cout << "Deleted 30\n";
    else 
        cout << "Value not found\n";

    cout << "Doubly Linked List after deletion (Forward): ";
    list.displayForward();

    cout << "Doubly Linked List (Backward): ";
    list.displayBackward();

    return 0;
}
