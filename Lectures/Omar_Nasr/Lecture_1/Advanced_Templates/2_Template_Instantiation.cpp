#include <iostream>
using namespace std;

template <typename T>
void refFunc(T& x) {  // Expects a non-const lvalue reference
    cout << "Reference: " << x << endl;
}

int main() {
    int a = 10;
    refFunc(a);  //* Works fine

    // refFunc(20);  //! Compilation Error: Can't bind `int&` to a temporary
    return 0;
}
