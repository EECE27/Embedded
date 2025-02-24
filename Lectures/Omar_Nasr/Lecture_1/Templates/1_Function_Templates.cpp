#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Addition of integers: " << add(10, 20) << endl;   // Calls add<int>
    cout << "Addition of doubles: " << add(5.5, 2.2) << endl; // Calls add<double>
    return 0;
}
