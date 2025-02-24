#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Compare {
public:
    bool isEqual(T a, T b) {
        return a == b;
    }
};

// Specialization for char*
template <>
class Compare<char*> {
public:
    bool isEqual(char* a, char* b) {
        return strcmp(a, b) == 0;
    }
};

int main() {
    Compare<int> intCompare;
    cout << intCompare.isEqual(10, 10) << endl; // 1 (true)

    Compare<char*> strCompare;
    cout << strCompare.isEqual("hello", "hello") << endl; // 1 (true)
    
    return 0;
}
