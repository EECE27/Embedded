#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance; // Private member

public:
    void setBalance(double b) { balance = b; }
    double getBalance() { return balance; }
};

int main() {
    BankAccount acc;
    // acc.balance = 1000;  // ❌ ERROR: 'balance' is private
    acc.setBalance(1000);
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}
