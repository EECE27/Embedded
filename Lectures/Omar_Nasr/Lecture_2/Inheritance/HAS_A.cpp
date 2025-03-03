#include <iostream>

using namespace std;

class Base 
{
    public:
        int publicVar = 1;

    protected:
        int protectedVar = 2;

    private:
        int privateVar = 3;
};

class Derived : private Base
{
    public:
        void show()
        {
            cout << "PublicVar: " << publicVar << endl;   // ✅ Became private in Derived
            cout << "ProtectedVar: " << protectedVar << endl; // ✅ Became private in Derived
            // cout << "PrivateVar: " << privateVar; // ❌ ERROR: Not accessible
        }
};

int main()
{
    Derived obj;
    obj.show();
    // cout << obj.publicVar; // ❌ ERROR: Now private!
    return 0;
}
