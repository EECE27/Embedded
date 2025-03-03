#include <iostream>
using namespace std;

class Base
{
    public:
        int publicVar = 1;

    protected:
        int protectedVar = 2;

    private:
        int privateVar = 3; // ❌ Not accessible in derived class
};

class Derived : public Base {
public:
    void show() {
        cout << "PublicVar: " << publicVar << endl;   // ✅ Accessible (public)
        cout << "ProtectedVar: " << protectedVar << endl; // ✅ Accessible (protected)
        // cout << "PrivateVar: " << privateVar; // ❌ ERROR: Not accessible
    }
};

int main() {
    Derived obj;
    obj.show();
    cout << "Accessing from main: " << obj.publicVar << endl; // * Accessible
    // cout << obj.protectedVar; // ! ERROR: Still protected
    return 0;
}
