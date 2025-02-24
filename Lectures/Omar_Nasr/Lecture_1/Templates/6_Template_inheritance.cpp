#include <iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T value;
public:
    Base(T val) : value(val) {}
    void show() { cout << "Value: " << value << endl; }
};

template <typename T>
class Derived : public Base<T> {
public:
    Derived(T val) : Base<T>(val) {}
    void increment() { this->value++; }
};

int main() {
    Derived<int> d(5);
    d.increment();
    d.show();  // Outputs: Value: 6
    return 0;
}
