#include<iostream>
using namespace std;


class Stack{
public:
    int *arr;
    int size;
    int top;

    Stack(int s){
        this->size=s;
        this->top=-1;
        this->arr=new int[size];
    }

    int size(){
        return this->top;
    }

    void pop(){
        if(this->top!=-1){
            this->top=this->top-1;
        }else{
            cout<<"Stack is Empty!";
        }
    }

    void push(int data){
        if(this->top < this->size){
            arr[this->top]=data;
            this->top++;
        }else{
            cout<<"stack is full";
        }
    }

    int top(){
        if(this->top !=-1){
            return arr[this->top];
        }else{
            cout<<"Stack is Empty";
            return
        }
    }
};


int main(){
    Stack st=Stack(5);
    st.pop();
    
    return 0;
}