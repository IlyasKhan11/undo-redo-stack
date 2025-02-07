#include<iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

    Queue(int s){
        this->arr = new int[s];
        this->capacity = s;
        this->size = 0;
        this->front = 0;
        this->rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull(){
        return size == capacity;
    }
    
    bool isEmpty(){
        return size == 0;
    }

    void push(int d){
        if(isFull()){
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = d;
        size++;
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int top(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main(){
    Queue q(5);
    q.push(5);
    q.push(1);
    q.push(1);
    q.push(1);
    cout << "Front element: " << q.top() << endl;
    q.pop();
    cout << "Front element after pop: " << q.top() << endl;
    return 0;
}
