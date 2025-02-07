#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) { // Constructor
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head; // Pointer to the head node

public:
    // Constructor
    LinkedList() {
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

        // If the head node is to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return false; // Value not found

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return true;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Driver code
int main() {
    LinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Linked List after insertion: ";
    list.display();

    // Update a node
    if (list.update(20, 25)) 
        cout << "Updated 20 to 25\n";
    else 
        cout << "Value not found\n";
    
    cout << "Linked List after update: ";
    list.display();

    // Delete a node
    if (list.deleteNode(30)) 
        cout << "Deleted 30\n";
    else 
        cout << "Value not found\n";

    cout << "Linked List after deletion: ";
    list.display();

    return 0;
}
