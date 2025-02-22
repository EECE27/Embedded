/*
    Scenario: Using a Pointer Without Initialization
    A pointer that is declared but not initialized can point to random memory.
*/

int* p;
*p = 20;  // Undefined behavior! p points to an unknown location

// Solution: Always Initialize Pointers


int* p = nullptr;

//🔹 Key Takeaway: Always initialize pointers to nullptr before use.