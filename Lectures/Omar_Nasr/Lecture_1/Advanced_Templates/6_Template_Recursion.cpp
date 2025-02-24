#include <iostream>
using namespace std;

template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {  // Base case
    static const int value = 1;
};

int main() {
    cout << "Factorial of 5: " << Factorial<5>::value << endl; // Output: 120
    return 0;
}
