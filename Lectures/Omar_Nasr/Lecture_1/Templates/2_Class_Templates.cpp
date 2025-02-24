#include <iostream>
using namespace std;

template <typename T>
class Box {
    T value;
public:
    Box(T val) : value(val) {}  // Constructor
    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> intBox(100);
    Box<double> doubleBox(99.99);
    
    intBox.show();
    doubleBox.show();
    
    return 0;
}
