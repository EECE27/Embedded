#include <iostream>
using namespace std;

template <typename T>
T divide(T a, T b) {
    return a / b;
}

// Specialization for int to handle division by zero
template <>
int divide<int>(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    cout << divide(10.5, 2.5) << endl;  //* Works fine
    cout << divide(10, 2) << endl;      //* Works fine
    cout << divide(10, 0) << endl;      //! Special case handled
    return 0;
}
