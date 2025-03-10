#include <iostream>
using namespace std;

class Stack {
private:
    static const int max = 100;
    int arr[max];
    int top;

public:
    Stack() { top = -1; }
    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    int peek();
};

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::isFull() {
    return (top >= max - 1);
}

void Stack::push(int x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
    } else {
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return 0;
    } else {
        int x = arr[top];
        return x;
    }
}

// Demonstrate the stack in action
int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << myStack.pop() << " Popped from stack\n";
    // Show the top element
    cout << "Top element is " << myStack.peek() << endl;

    return 0;
}
