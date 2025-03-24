## Review:
- I/O processing
	- Polling
	- Interrupt based

## **Embedded Programming Architectures:

### Bare Metal (Super Loop):

Example:
```C
int main(void)
{
task1_init();

	while(1)
	{
		task1();
		task1();
		task1();
		task1();
		.
		.
		.
		
	}
}
```

#### Disadvantages:
- **Timing Issues:
	- Tasks must be executed in a sequential order, might cause problems for time critical applications
	- Say one of the tasks has a certain deadline based task, a sequential order might delay that that deadline
	- This can be fixed in code but might not work for all cases and makes the code non-protable.
### Bare Metal (Event Driven):

Example:
```C
int main(void)
{
	inits();
	initDispatchQueue();
	
	while(1)
	{
		WaitForNextEvent();  // Sleep till the event occurs
		//(wait for An event to enter the event or dispatch queue)
		// ISR Defines the event and stores in global variable i.e: SystemState
		// Back from ISR
		switch(SystemState)
		{
			case StateA:HandleStateA(); break;
			case StateB:HandleStateB(); break;
			.
			.
			.
		}
		
	}
}
```

#### Advantages:
- Can control the Dispatch queue and manage priorities
- Depends on interrupts which can be prioritized

#### Disadvantages:
- If Interrupt happens from 3 states, All events in queue must be completed in order, which might result in missing the deadline of the last state.
	- *Solution: Exchange Switch statement to If statement to continuously check for C, A->C->B->C...
		-Improves C but the rest suffer, Not very practical.


### RTOS/OS Based Architecture:

```C
void Task1()
{
	while(1)
	{
		wait for signal
		Handle Event or Data
	}
}

void Task2()
{
	while(1)
	{
		Wait for signal
		Handle Data/Events
	}
}

void app_main(void)
{
	initSystem();
	CreateTask(Task1,Task1_Priority);
	CreateTask(Task2,Task2_Priority);
	StartScheduler(); // Program starts and never returns
}
```
```C
// Interrupts

void interruptHandleDevA()
{
	Handle A
	Set X
}



```

- Tasks Run in parallel with each other.
- Time Bounded tasks can be given higher priorities.
- Tasks are Rounded so that virtually it looks like they are running in parallel to each other.

#### Advantages:
- Tasks can cut each other according to priority and states.
- Supports Task Scheduling
- System becomes more modular and editable
	- Can easily add extra tasks and set its priority

### Disadvantages:
- Bigger Code Size
- More Complex
- Some are not free and require licenses
- Problems might arise like deadlock and inversion (Stay Tuned...)
- **Task Starvation:**
	  if a task required 100% CPU and didn't wait on anything, only the highest priority task in the system is getting the CPU time and other tasks are starved.
	  - Usually caused by wrong design or a developer fault.

### Well-Known RTOS:
- FreeRTOS: owned by AWS but still free and very popular (Our RTOS of choice for the syllabus)
- Threadx: Owned by Microsoft, Also Free the Professor's Favourite and has an elegant API
- Keil RTX: ARM Software, Free
	.
	.
	.
	.
And  a bunch more.....