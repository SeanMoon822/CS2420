/*
filename: Assignment_P1.cpp
Developer Name: Seonghyun Moon
Date: Apr.26th.2023
*/
#include<iostream>
#include<string>
using namespace std;

const int SIZE = 10;

class Stack 
{
    private:
        int top;
        int arr[SIZE];

    public:
        Stack() 
        {
            top=-1;
            arr[SIZE]={0};
            
        }
        //Create a Stack constructor using a fixed length array.
        bool isEmpty() 
        {
           return top==-1;
        }
        //Make a fuction that checks if the stack is empty.
        bool isFull() 
        {
            return top==SIZE-1;
        }
        //Make a fuction that checks if the stack is full.
        void push(int value) 
        {
            if (isFull()) 
            {
                cout << "Stack is full." << endl;
            }
            else
            {
                arr[++top]=value;
            }
        }
        //Make a function that inserts new element on top if the stack is not full.
        void pop() 
        {
            if (isEmpty()) 
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                top--;
            }
        }
        //Make a function that deletes top element if the stack is not empty.
        int Top() 
        {
            if (isEmpty()) 
            {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            else
            {
                return arr[top];
            }
        }
        //Make a function that returns the top element if the stack is not empty.
        
};
//Make a Stack Class.

int main() 
{
    Stack s;
    //Make an object for the class.
    cout << "isEmpty(): " << s.isEmpty() << endl;
    cout << "isFull(): " << s.isFull() << endl;
    s.push(1);
    s.push(2);
    cout << "Top element: " << s.Top() << endl;
    s.pop();
    cout << "Top element: " << s.Top() << endl;
    return 0;
}
