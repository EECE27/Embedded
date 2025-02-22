#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;
    int** ptr2 = &ptr; // Pointer to pointer

    cout << "Value of x: " << x << endl;
    cout << "Value at *ptr: " << *ptr << endl;
    cout << "Value at **ptr2: " << **ptr2 << endl;

    return 0;
}
