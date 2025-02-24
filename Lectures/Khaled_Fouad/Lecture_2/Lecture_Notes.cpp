#include <iostream>

using std::cout, std::string;

/*
? Remainig Part of Last Lec
    Coding Standards:
    - Misra C/C++ (Very Important)
    - Autosar
    - ISO 17961 (Secure C) security stuff
    - CERT C (Institute concerned with cypersec)
    todo: Consider studying them to get training opprotunities in summer

? Embedded Development Framework:
    -Check Slides for good resources

    ? Typical Embedded Board:
    - Microprocessor/Controller
    - Ram/Memory and cache
    - Flash ROM/Chip for booting : Contains Boot Image, Loader (subject of today's lec), Target Monitor (used for communication between board and host pc)
    - Jumper pins and headers for adjusting specific functions (Look at an image of an STM32 Blue Pill this have such jumpers): JTAG, BDM
    - Software on Embedded system is called Firmware
    - They work on low power especially batteyr operated devices / they have work cycles to optimize battery consumption

    Lap infront of 8310 open to use with different embedded boards for testing and learning as long as it is inside the college.

    ? Build Process:
    - Code is written on a normal computer with a development enviroment and toolchains built for running code on the target processor
    (Cross Compilers/Toolchains).
    Also Gives me information about the memory usage according to the target hardware specified by the programmer before the process.

    ? Compiler: GNU GCC
    1- C Code (.c .cpp .h files)
    2- Pre-Processor: done on .h files (text replacement) -> output .i file.
    3- Compiler: Check syntax and generate assembly code appropriate for the target controller. -> .asm file
    4- Assembler: Takes assembly code and generates -> .o .coff (rare) .elf (Executable and Linkable Format) Object file
    5- Linker: Links all different Object files and External Libraries and generates one Binary/Executable File -> .exe .hex ......

    Object File is important to understand its structure and read it to troubleshoot problems or ensure optimizations.

   ? Object Code Sections:
        4 Sections
   Text (.Text): Machine code and instructions stored on processor.
   Data (.data): COntains intialized Global Variables and their Intial Variables
   BSS (.bss) (Block Started By Symbol): Unintialized Global Variables as well as static global. 
   Startup Code: intializes the variables to zero
   -Gets its name cuz historically it had a symbol at the beginning of the block (Doc Hates the name) just know what it contains
   Symbol Table: contains names and lovations of all variables and functions referenced within the source file.
        - It is used by the Linker to resolve the locations of all functions and variables during the linking process.

   ! Everything applied on Global Variables is applied on Static Variables.


*/

                /*Code Example*/
#include <stdio.h>

const int myArray[] = {1, 2, 3, 4}; //  Const global variable intialized goes to -> .text
int data_sec_Var = 5; // Global Intialized goes to -> .data
int bss_sec_Var; // Unitialized goes to -> .bss
int myfunc()
{
    static int j = 0; // static intialized goes to data
    j++; // Local Variables -> Stack
    return j;
}

int main()
{
    int i = myfunc(); // Reference to local Function
    printf("i = %d\n", i); // Unresolved reference to library function (Linker resolves it)
}

/*
    ? Program Memory Map:
    -Range of addresses is determined by the address bus of the processor.
    -As a programmer u can map the memory layout however you like by editing linker scripts,
    though there's a default way of doing it done by linker scripts.
    todo: Check Slides for exact memory layout diagram
    -Memory Layout typically contains same sections described before in addition to Stack and Heap.
    - Symbol table is not part of the memory layout as it is only used by the linker
    - Typically Stacks grows from High address to Low -> Local Variables and Context Switching
    !ew3a t3ml pop 2bl ma t3ml push
    - Heap grows from Low to High -> Dynamic Memory allocation and other programmer utils, Controlled by the programmer mostly. used during runtime

    ! DO NOT USE RECURSION IN EMBEDDED -> MISRA C Gives errors
    * Main cause of errors and stack overflow in Embedded.

    ? Typically Dynamic Memory allocation done only at the beginning of the code
    ! NO DYNAMIC MALLOC OR NEW OTHERWISE AND DURING RUNTIME.
    ? Operating Systems (FreeRTOS, AutosarOS) have functions for Memory Pools to do as an alternative to Dynamic Allocations
    todo: Check Memory Pools and their libraries

    "size" Program can be used to get output containing sizes of each block in the memory map.
    "objdump" Program can be used to display assembly contents of each different sections.

    todo: Learn linux the previos program as linux commands. (Try WSL: Windows Subsystem for Linux, VM Alternative)

    ? Linker (ld in gnu):
    Libraries:
      1- Static: Linked directly with exe file
      2- Shared Object(.SO)/.DLL: Multiple exe can call them at run time at the sametime, used to save memory.
            - SO in linux, DLL in windows, Called to SO/DLL is managed by OS (typically not used in embedded applications).
    - More Info about Linker is the same as the things mentioned the previous sections here
    check slides for all its functions combined in one slide.


    ? Startup Code:
    - In embedded systems, code doesnt start directly in Main Function
    - Startup code intializes devices and gets things ready then puts the address of the main function in the PC at the end to start the program.

    ? Loader / Locator:
    - Communicates with Host PC to burn code inside the flash memory of the MCU
    - Calls vectors in the Vector Table (Next Lecture Topic)

    todo: Exercise
    arm-none-easbi-gcc
    arm-none-eabi-ld
    arm-none-eabi-objdump
    arm-none-eabi-size
    ? Do the build process manually using the building commands and visualize the size and contents of Binary files with objdump and size


    ? Bootloader/ Bootstrapping an MCU:
    - Special program responsible for starting program and loading the image.
    - Usually processor/board dependant, supplied by manufacturer.
    - A good exercise is experimenting with writing bootloaders for specific boards.
    
    * Process (General Overview):
    - Starts upon reset of an embedded system: Address of Reset Vector is called. (Hard-Wired)
    - Launches bootloader code
    - Intialize board Hardware (Peripherals etc..).
    - Check object on flash or ROM
            - Download ELF from host to RAM
    - If compressed it will get decompressed.
    - Create exectuable image in RAM
    - Call Main function and start program execution.

    ? Startup Code:
    - Disables all interrupts (Except Reset).
    - Copy unitalized/global/static variables from fash to .data in the RAM memory
    - intialize unitialized variables in .bss to 0
    - Intialize Stack Pointer after allocating space to stack.
    - Defines IVT (Interrupt Vector Table).
    - Enable interrupts.
    - Call the main Functions
    
*/