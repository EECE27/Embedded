#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of ptr (address of x): " << ptr << endl;
    cout << "Value at ptr (*ptr): " << *ptr << endl;

    return 0;
}
