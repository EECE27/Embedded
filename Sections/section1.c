#include <stdio.h>

// First Section talks about Pointers
// Mohamed Riad: Interfacing -> Interconnections in Year 3 (Internal Wiring in the IC) 
// Data Structures (AI) -> Dr Omar Nasr.

int main(void)
{
    int (*A)[5];    // Pointer to an Array of 5 Elements
    int B[5];       // Array of % elements
    int *(*C)[5];   // Pointer to Pointer to Array of 5 Elements

    printf("%d %d %d\n", A, B, C);  // Visualize initial address in each
    printf("%d %d %d\n", A + 1, B + 1, C + 1);  // Visualize the step taken by the pointer
}