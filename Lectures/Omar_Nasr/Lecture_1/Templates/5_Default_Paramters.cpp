#include <iostream>
using namespace std;

template <typename T = int>
class Value {
    T data;
public:
    Value(T d) : data(d) {}
    void show() { cout << "Value: " << data << endl; }
};

int main() {
    Value<> defaultValue(10);   // Uses int as default
    Value<double> doubleValue(5.5);

    defaultValue.show();
    doubleValue.show();
    
    return 0;
}
