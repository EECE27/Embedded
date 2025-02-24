#include <iostream>
using namespace std;

template <typename T, typename... Args>
void print(T first, Args... rest) {
    cout << first << " ";
    if constexpr (sizeof...(rest) > 0) {
        print(rest...);  // Recursive call
    }
}

int main() {
    print(1, 2.5, "Hello", 'A'); // Outputs: 1 2.5 Hello A
    return 0;
}
