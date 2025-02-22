#include <iostream>

void modifyReference(int& num) {
    num = 50; // Modifies the original variable
}

int main() {
    int x = 10;
    modifyReference(x);
    std::cout << x; // Output: 50
}
