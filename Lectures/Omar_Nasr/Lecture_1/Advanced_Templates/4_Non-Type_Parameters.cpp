#include <iostream>
using namespace std;

template <typename T, int SIZE>
class Array {
    T arr[SIZE];
public:
    void fill(T value) {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = value;
        }
    }
    void show() {
        for (int i = 0; i < SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int, 5> myArray;
    myArray.fill(10);
    myArray.show();  // Output: 10 10 10 10 10
    
    return 0;
}
