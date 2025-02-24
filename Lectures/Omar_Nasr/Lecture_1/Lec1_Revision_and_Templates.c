#include <stdio.h>

// Dr Omar Nasr
// E-mail: omaranasr@cu.edu.eg
// Phone Number (Whatsapp): 01143941832

/*                 Data Structure and Algorithms (DSA)                     */

/*
    AI Clients:
    - Claude
    - V0: Describe app and creates entire front-end

    What is Data Structures and why do we need them?
    - Data is not like each other.
    - Thats why it needs to be stored in different ways

    Examples of Data Structures:
    - Linked Lists
    - Dequeues
    - Trees
    - Hash Tables
    - Graphs
    - Skip Tables
    ....
    ..
    .

    Why different Data Structures:
    - Check Slides, has a table of data structures and the different complexities of all operations that can be done on each
    - This is what differentiates data structures from each other.
    - The table is probably not to be memorized, but offers great insights on the reasons for exsitance of different data structures
    and how each one can used for what. as well as understanding complexities.
    (Best Case, Worst Case and Average Case) -> Complexities.

    - Prof loves Hash Tables because its an O(1) in all operations and is used for all databases (Very Smart).\

    Data structures like: Arrays and list are considered "Linear DS"
    While DSs like: Trees, Graphs, are "Non-Linear DS"

    What is Cache:
    - It is memory very close to the microprocessor on the same die.
    very fast can execute operations in 1 Clock cycle.
    - RAM is very slow compared to it, takes around 100 clock cycles for operations.

    Everyting taught in DSA and done by hand is actually available in libraries.
    - Search on Geeks4Geeks: C++ Standard Template Library (STL).
    - It conatins implementations of most Data Strucutres as well as their functions and algorithms. 
    - Python also has the same.


    Reviewing Older info with examples.
    - Pointer is a Data Type/Variable that stores Addresses.
    - Pointer Arithematic: Incrementing pointer and doing arithmatic operations on them
    The step by which the pointer is affected is determined by its Data Type (int, float, array .....)
    - Passing pointers to functions (Call by reference or by pointer)
    - Dynamic Memory allocation using: "new int" and "delete"
    Dynamic Memory allocation of arrays using "new int[n]"
*/

/*
    Templates:

    Two types of applications:
    - Compile Time
    - Run time

    They allow certian functions to work with different data types and do the same thing.

    It's a blueprint.

    Function Templates:
    - works for functions and classes.
    
    Sytanx:
    template <typename T>
    T add(T a, T b)
    {
        return a + b;
    }

    where "T" is a generic Data Type.

    The Function "add" can now be called anywhere
    - The Data-Type "T" is determined by the Compiler during Compile-Time every time the compiler is called.
    so that the specific operations and the way of storing the variable used by the compiler can be determined.
    - A copy of the function is created for each data-type during compile time.

    for the syntax, typename and class be be used interchangebly

    Class Templates:

    syntax:
    template <typename T>
    class box
    {
        T Value;
    public:
        Box(T val) : value(val) {}  
        /
        Box(T val)
        {
            val = val;
        }
        /
        void show()
        {
            cout << "Value: " << value << endl;
        }
    }
*/

/*
    Complexities:

            Space Complexity VS Time Complexity

    Definitions are in the slides, but its pretty self explanatory.

    -Order of 1 O(1), best case doesnt depend on the size of the structure/array.
    -O(log(n)) increases in a non-linear logarithmic scale, more effecient than a linear one.
*/

int main()
{
    printf("Hello World\n");
}

