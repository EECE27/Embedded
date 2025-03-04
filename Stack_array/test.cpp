#include <iostream>

using namespace std;

#include "stack.h"

int main(void)
{
    stack <string>myStack;

    myStack.push("Hello");
    myStack.push("World");
    myStack.push("Ameer");

    cout << myStack.peek() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.peek() << endl;

    return 0;
}