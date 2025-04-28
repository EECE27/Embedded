Last time in RTOS:
- Shared Data/Resource Problem
- All separate tasks in an embedded program share a memory space.
### Re-entrant Functions:
```C

void Task1()
{
	.
	.
	.
	.
	vCountErrors(9);
	.
	.
	.
}

void Task2()
{
	.
	.
	.
	vCountErrors(11);
	.
	.
	.
}

static int cErrors = 10;

void vCountErrors(int cErrorCounter) // Non-reentrant function
{
	cErrors += cErrorCounter;
}
```

Re-entrant functions are used by multiple tasks using the same variables, causing potential chances for corruption, it must satisfy the following three rules to work as expected:
- Does not use variables in a non atomic way unless stored on the stack or are private variables of the task
- Does not call any other function that is non-reentrant itself
- Doesnt not use hardware in a non-atomic way.

> Pro Tip: All of the C standard library functions are Re-Entrant and can be used safely

### Mutual Exclusion: Semaphores:
Real life example first:
- They refer to in train tracks to avoid trains from colliding with each other.
- A Semaphore lowers when a train1 enter a track.
- Train2 waits until the semaphore is raised again
- As soon as it is raised train2 enter and lowers the semaphore again
The train here is the variable and the track is the critical section in the code

Only one task can be using a critical section at a time.

> Check the slides for a really good graphic on how Semaphores in FreeRTOS code actually work

When a task cant use a resource because its semaphore is taken it goes to a blocked state and waits till the semaphore is released.
Once the semaphore is released and the scheduler realizes that the task is now ready, it this usually done using a queue data structure to make out which tasks were waiting in first to execute in the correct order. (Scheduler manages that)

> Semaphores can even Block high priority tasks, thats why critical sections must be small in size and using a small amount of CPU clock cycles.

```C

void Task1()
{
	.
	.
	.
	.
	vCountErrors(9);
	.
	.
	.
}

void Task2()
{
	.
	.
	.
	vCountErrors(11);
	.
	.
	.
}

static int cErrors = 10;
static NU_SEMAPHORE semErrors;

void vCountErrors(int cErrorCounter) // Re-entrant function
{
	NU_Obtain_Semaphore(&semErrors, NU_SUSPEND);
	cErrors += cErrorCounter;
	NU_Release_Semaphore(&semErrors);
}
```

Mutual-Exclusion is now assured, There is a different method called **Mutex.

> You may google counting semaphore by yourself, not part of the course.

### **Semaphores as signalling mechanism:
Very useful for project

Must ensure that a single user can be sending through the channel at the same time, this can be done using a semaphore.

It is better than polling and continuously asking the IO port if there is new data

### **Difference between Semaphore in Mutual Exclusion and Signalling Mechanism:

- In Mutual Exclusion: Semaphore is initially available to show that a variable is available to use.
- In Signalling Mechanism: Semaphore is initially **Not Available** showing that there is no data to receive, and only made available when data is available.
### Deadly Embrace Problem:

Say for example, Two Tasks: Task1, Task2

They both require two resources A and B and take their semaphores at the beginning of the code execution

```C

void Task1()
{
	xSemaphoreTake(semA);
	xSemaphoreTake(semB);
	// Do Stuff
	xSemaphoreGive(semB);
	xSemaphoreGive(semB);
}

void Tas21()
{
	xSemaphoreTake(semB);
	xSemaphoreTake(semA);
	// Do Stuff
	xSemaphoreGive(semA);
	xSemaphoreGive(semB);
}
```

What would happen if task2 starts before Task1 finished taking the second semaphore?
(Right after semA is taken).

both tasks require the two semaphores but both can only use one of each, results in both tasks being blocked and waiting for the semaphore to be released which will never happen since both cant execute.

This is **Deadly Embrace.** bye bye ya system.

>Prof Says modern tools have automatic checks to prevent such a problem, but as a developer you must have a sense for such things

**Solution is Simple!

```C
// Solution

void Task1()
{
	xSemaphoreTake(semA);
	xSemaphoreTake(semB);
	// Do Stuff
	xSemaphoreGive(semB);
	xSemaphoreGive(semA);
}

void Tas21()
{
	xSemaphoreTake(semA);
	xSemaphoreTake(semB);
	// Do Stuff
	xSemaphoreGive(semB);
	xSemaphoreGive(semA);
}
```

Taking the two semaphores in the same order in the two tasks, ensures the deadly embrace does not happen. must do the same thing in during releasing the semaphore but the opposite, treat it like a stack.

> Do not use semaphores in ISRs, keep it away from semaphores and use buffers or other use to store the data in the ISR.
> And always keep them short and precise.


### **Priority Inversion

Lets see the following scenario

- Task C is a low priority, takes a semaphore
- RTOS switches to higher priority Task B which is medium priority
- Task A with High Priority starts running but uses Semaphore taken by C, so it goes to a blocked state.
- Task B starts running, and keep on running, blocking both Task A and C from running even though A is higher Priority

**Solution:** Make Task C the same priority as Task A as long as the semaphore is taken -> Priority Inheritance.

> This is done automatically by the scheduler

#### Mars Pathfinder Incident

- Starts experiencing repeated RESETs after starting gathering of meteorological data
- RESETs are Generated by Watchdog Process.
- Timing Overruns caused by **Priority Inversion.

Two tasks one low priority and one high priority using the same semaphore without priority inheritance causing the high priority task being blocked for long periods of time prompting the watchdog timer to reset the system continuously

A simple firmware update enabling priority inheritance during task creation, fixed the problem and the mission resumed successfully.
