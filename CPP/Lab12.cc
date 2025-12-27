/* 12 Write a C++ program that consists of Stack class and include methods to push and pop the stack elements. Create your own defined Exception class and handle exceptions 
while stacks run with “Stack as full” and “Stack under flow” while calling push() and pop() methods respectively. Implement this using „throws‟ and „throw‟ keywords.*/

#include <iostream>
#include <string>
using namespace std;

class StackOverflowException {
public:
    string message;
    StackOverflowException(string msg) { message = msg; }
};

class StackUnderflowException {
public:
    string message;
    StackUnderflowException(string msg) { message = msg; }
};

class Stack {
    int top;
    int size;
    int *arr;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (top == size - 1)
            throw StackOverflowException("Stack Overflow! Cannot push element.");
        arr[++top] = x;
        cout << x << " pushed to stack." << endl;
    }

    void pop() {
        if (top == -1)
            throw StackUnderflowException("Stack Underflow! Cannot pop element.");
        cout << arr[top--] << " popped from stack." << endl;
    }

    void display() {
        if (top == -1)
            cout << "Stack is empty." << endl;
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack s(3);
    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.display();
        s.push(40); // Will throw overflow exception
    } 
    catch (StackOverflowException &e) {
        cout << "Exception caught: " << e.message << endl;
    }

    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop(); // Will throw underflow exception
    } 
    catch (StackUnderflowException &e) {
        cout << "Exception caught: " << e.message << endl;
    }

    return 0;
}