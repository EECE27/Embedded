#include <iostream>

using namespace std;

/*
    Scenario: Accessing Memory After It Has Been Freed
    If a pointer refers to memory that has been deallocated, it results in undefined behavior.
*/


int* createPointer() {
    int a = 10;
    return &a; // Dangerous! a is a local variable and will be destroyed
}

int main() {
    int* p = createPointer();
    cout << *p << endl;  // Undefined behavior: accessing invalid memory
    return 0;
}

//  Key Takeaway: Never return the address of a local variable from a function. Instead, allocate memory dynamically.