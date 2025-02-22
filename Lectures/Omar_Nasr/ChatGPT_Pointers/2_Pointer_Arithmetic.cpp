#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40};
    int* ptr = arr; // Points to first element

    cout << "First element: " << *ptr << endl;
    ptr++;  // Move to next element
    cout << "Second element: " << *ptr << endl;
    ptr += 2; // Move 2 elements forward
    cout << "Fourth element: " << *ptr << endl;

    return 0;
}
