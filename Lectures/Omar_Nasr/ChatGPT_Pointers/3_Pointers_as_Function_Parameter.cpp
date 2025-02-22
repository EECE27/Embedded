#include <iostream>
using namespace std;

void modifyPointer(int* ptr) {
    *ptr = 50; // Modifies the original value
}

int main() {
    int x = 10;
    modifyPointer(&x);
    cout << x; // Output: 50 (changed)
}
