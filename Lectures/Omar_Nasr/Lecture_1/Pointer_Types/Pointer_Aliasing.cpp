#include <iostream>
using namespace std;

/*
   ? Scenario: Multiple Pointers Pointing to the Same Memory
   ? If two pointers reference the same memory, modifying one affects the other.

*/

int main() {
    int x = 42;
    int* p1 = &x;
    int* p2 = p1; // Both p1 and p2 point to x

    *p2 = 99; // Modify value using p2

    cout << "x: " << x << endl;  // Output: x: 99
    cout << "*p1: " << *p1 << endl;  // Output: *p1: 99
    cout << "*p2: " << *p2 << endl;  // Output: *p2: 99

    return 0;
}

// Key Takeaway: Changing *p2 also modifies *p1, since both point to the same address.