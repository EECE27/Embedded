#include <iostream>

using namespace std;

void memoryLeak() {
    int* p = new int(10);
    // Memory is allocated but never freed
}

//🔹 Key Takeaway: Always use delete or delete[] after using new or new[].


// Corrected Code


void noMemoryLeak() {
    int* p = new int(10);
    delete p;  // Free the memory
}
