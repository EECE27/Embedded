#include <iostream>
using namespace std;

class Student {
public:
    string name;

    // Constructor
    Student(string n) {
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Student s1("John"); // Constructor called automatically
    return 0; // Destructor called automatically
}
