#include <iostream>
using namespace std;

template <typename T>
void display(T value) {
    cout << "Value: " << value << endl;
}

int main() {
    display(5.5);   //* Works fine (T deduced as double)
    display(5);     //* Works fine (T deduced as int)
    display('A');   //* Works fine (T deduced as char)

    // display(5.5f, 10);  //! Compilation Error: Too many arguments
    return 0;
}
