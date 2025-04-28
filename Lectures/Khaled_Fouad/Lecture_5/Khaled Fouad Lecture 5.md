## **Introduction to Real-Time Embedded Operating Systems:
- What is RTOS
- Tasks: States COntexts memory address space
- scheduling
- tasks and data: Reentrant functions
- Mutual exclusion
- Inter task communication

Check slides for useful references, could help in the project:
- Ch6 Embedded Software primer, David E. Simon
- Mastering FreeRTOS

## **Introduction to Operating Systems:
- Its a computer program.
- Processes are instances of a program in memory
- OS Manages Processes
- OS can be:
	- Single Task
	- Multi-Task
	Tasks here are processes as not to be confused with tasks in FreeRTOS
	
**Prof Tip: If you want to get better in Coding consider learning and implementing how to write a piece of an OS or a Compiler

- Provides an abstraction of the Physical Machine
	- Allows you to write code for any machine regardless of the hardware
- Simple Interface
- Each part is called "Service"

**Check Slides for Computer System Layers: User-Level, Programmer-Level, System-Level, HW-Level.
- There are layers beyond these, as can be seen in VMs (Virtual Machines).

## **Back to Embedded:
- They Mostly run singles tasks/process, either running bare-metal (Normal C programs like we do), or under an OS (like we will do using RTOS, embedded linux, andy embedded OS)
- Can be structured as set of different threads or tasks.
- All processes in an Embedded System share the same memory address space.
	- Global Variables and static
	- same Program Counter, Registers and stack
**Refer to last lecture (Architecture Lecture) to get to know the different ways an Embedded Program is structured.

## **RTOS Based Architecture

From Last Lecture:
```c
void InterruptHandlerDevA()
{
	Handle Device A
	Set Signal X
}

void InterruptHandlerDevA()
{
	Handle Device A
	Set Signal X
}

void task1()
{
	while(1)
	{
		// Do Stuff
	}
}

void task1()
{
	while(1)
	{
		// Do Stuff
	}
}

void main(void)
{
	systeminit();
	CreateTask(Task1, Task1_priority);
	CreateTask(Task2, Task2_priority);
	start_scheduler();
}
```

**Switching between tasks is called Context Swithcing.

## **Types of Real-Time:
Embedded tasks don't actually run in real time as the same time because Embedded Systems are usually single core, but they use techniques to appear as if they are **Virtually** Running in Real time.

They use techniques like Round-Robin, in which every tasks has a specific time frame and program continuously switch between tasks.

- **Hard Real-Time:** has very tight deadlines for completing tasks, which cannot be surpassed (A few millisecond), Can be seen in sensitive and deterministic application that require a high degree of safety (i.e Airbag in cars, Airplane Wing adjustment).

- **Firm Real-Time:** Missing a deadline may just result in lower quality which would be an inconvenience but not completely catastrophic (i.e tire pressure indicator).

- **Soft Real-Time** It is acceptable to miss deadlines as they can be recovered and done later (i.e Transmitting packets over wifi, if it is missed the router will transmit the packet again).

## **RTOS Task Management:
- Program is a set of cooperating tasks each with functions and deadlines.
- RTOS Scheduler is what manages all that according to the info given to it by the developer in the app_main() function

#### Coperative Multitasking
 - Task completed followed by the next tasks and so on, no task cuts the one before it
 Round Robin Algorithm

#### Pre-emptive Shcheduler
- Tasks can cut each other to meet the deadline requirements of Higher Priority tasks.
- **Used mostly in Hard Real-Time
- Does context switching to save the states of the cut tasks so that it can be completed later on.
Round Robin with Priority

Must adjust the Delta-Time of the time slot in which tasks exchange to be very large compared to the Time needed for context switching.

i.e Context switching in the CPU takes up to 100 CPU Cycles, Time slot has to be around 100,000 CPU Cycles, Context Switching is just 1% of the time slot.

### **Task States:
- **Running:** currently executed on CPU
- **Ready:** Task is waiting in the queue to run, waits for the scheduler to switch to it
- **Blocked:** Tasks is waiting for a certain event to occur (i.e task is sleeping, waiting for time to pass or interrupt to wake it up)
- **Suspended:** Tasks voluntarily suspends its execution and stays like that untill a "Resume" is called. (Available in FreeRTOS but not in every RTOS or OS)
```c
// Suspend Example

void Task()
{
	do_stuff();
	do_more_Stuff();
	
	suspend(); // Program stops and doesnt continue

	// Code after this is only executed after an external resume is called
	do_even_more_stuff();
	alot_more_stuff();
}

// This is a simple way a suspend can be used but it causes problems in debugging and makes understanding codes harder sometimes as tracking where the task is resumed is often difficult in bigger applications, thats why its not avaiable for some OSes
```

### **Shared Resources Problems:

Embedded Tasks by nature share the same resources, when tasks are running in parallel its common for a resource or variable be edited by a task/function while it is being used in a different task/function at the same time this could result in data corruption and unexpectable results.

Some programming techniques forbid using Global or Static variables to prevent these problems, but often time using them is necessary for sharing data around the program.

Marking certain functions of the code as "Critical Sections" where any interrupts during this section are disabled is a viable solution, but breaks the laws of hard rea-time systems, thats why critical sections must be very small and not include any loops or risks of failure of any sort.

More viable solutions will be discussed later....

Re-entrant functions...........
coming soon ™ 
