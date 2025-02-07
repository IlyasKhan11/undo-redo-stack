#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;
    int size;

    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void push(int d) {
        Node* newNode = new Node(d);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue q;
    q.push(5);
    q.push(1);
    q.push(1);
    q.push(1);
    cout << "Front element: " << q.top() << endl;
    q.pop();
    cout << "Front element after pop: " << q.top() << endl;
    return 0;
}
