#include<iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int s){
        this->arr = new int[s];
        this->size = s;
        this->front = -1;
        this->rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull(){
        return this->rear == size - 1;
    }
    bool isEmpty(){
        return front == -1 || front > rear;
    }

    void push(int d){
        if(isFull()){
            cout << "Queue Overflow" << endl;
            return;
        }
        if(isEmpty()){
            front = 0;
        }
        rear++;
        arr[rear] = d;
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
        if(front > rear) {
            front = rear = -1; // Reset queue when empty
        }
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
    return 0;
}
