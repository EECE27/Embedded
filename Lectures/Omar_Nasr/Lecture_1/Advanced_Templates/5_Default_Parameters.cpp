#include <iostream>
using namespace std;

template <typename T = int>
class Storage {
    T data;
public:
    Storage(T val) : data(val) {}
    void show() { cout << "Stored: " << data << endl; }
};

// Partial specialization for char* to avoid pointer issues
template <>
class Storage<char*> {
    char* data;
public:
    Storage(const char* val) {
        data = new char[strlen(val) + 1];
        strcpy(data, val);
    }
    void show() { cout << "Stored: " << data << endl; }
    ~Storage() { delete[] data; }
};

int main() {
    Storage<> intStorage(42);  // Uses int by default
    intStorage.show();

    Storage<char*> strStorage("Hello");
    strStorage.show();  // Properly handles char* allocation

    return 0;
}
