#include <iostream>
using namespace std;

class Car {
public:   // Access specifier
    string brand;
    int year;

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1;  // Object of class Car
    car1.brand = "Toyota";
    car1.year = 2020;
    
    car1.display();
    return 0;
}
