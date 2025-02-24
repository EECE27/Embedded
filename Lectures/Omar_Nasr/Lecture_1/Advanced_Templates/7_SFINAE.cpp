#include <iostream>
#include <type_traits>
using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value>::type>
void process(T value) {
    cout << "Processing numeric value: " << value << endl;
}

int main() {
    process(10);      //* Works (int is arithmetic)
    process(5.5);     //* Works (double is arithmetic)

    // process("Hello"); //! Compilation error: Not an arithmetic type
    return 0;
}
