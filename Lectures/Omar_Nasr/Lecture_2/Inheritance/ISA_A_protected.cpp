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

class Derived : protected Base
{
    public:
        void show() {
            cout << "PublicVar: " << publicVar << endl;   // ✅ Became protected
            cout << "ProtectedVar: " << protectedVar << endl; // ✅ Accessible
        }
};

int main()


{
    Derived obj;
    obj.show();
    // cout << obj.publicVar; // ❌ ERROR: Now protected!
    return 0;
}
