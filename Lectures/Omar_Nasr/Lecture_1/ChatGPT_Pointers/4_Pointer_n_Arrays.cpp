#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40};
    int* ptr = arr; // Points to first element

    for (int i = 0; i < 4; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }

    return 0;
}
