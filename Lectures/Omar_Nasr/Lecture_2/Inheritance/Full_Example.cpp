#include <iostream>

using namespace std;

class Employee {
public:
    string name;
    void work() { cout << name << " is working." << endl; }
};

class Manager : public Employee {
public:
    void makeDecision() { cout << name << " makes a decision." << endl; }
};

class Intern : protected Employee {
public:
    void learn() { cout << name << " is learning." << endl; }
};

class ThirdPartyContractor : private Employee {
public:
    void contractWork() { work(); } // Can use Employee's work() but no direct access
};

int main() {
    Manager m;
    m.name = "Alice";  // ✅ Allowed (public inheritance)
    m.makeDecision();

    Intern i;
    // i.name = "Bob"; // ❌ ERROR: name is protected

    ThirdPartyContractor c;
    // c.name = "Charlie"; // ❌ ERROR: name is private

    return 0;
}
