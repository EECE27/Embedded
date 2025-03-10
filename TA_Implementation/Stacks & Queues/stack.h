#include<stdlib.h>
#include<iostream>

using namespace std;

#define MAX_SIZE 100

class Stack
{
	public:
		int data[MAX_SIZE];
	    int top;

		// Constructor to create a new stack
		Stack(){
			// Index for the top of the stack
			top = -1;
		};

		// Check if stack is empty
		bool isEmpty() {
	   		return top == -1;
		}

		// Check if stack is full
		bool isFull() {
			return top == MAX_SIZE - 1;
		}

		// Return the value of the stack's top
		int peek() {
			if (!isEmpty())
	        	return data[top];
	        else
	        	return -1;
		}

		// Add an element to the stack
		void push(int val) {
			// Check if stack is not full
			if(!isFull()) {
				// Pre-increment the index
				data[++top] = val;
			} else {
		    	printf("----- Full Stack -----\n");
		   	}
		}

		// Remove an element from the stack and return the data
		int pop() {
		   int val;

		   // Check if stack is not empty
		   if(!isEmpty()) {    
		       val = data[top];
		       // Decrement the index
		       top--;
		       // Return the data
		       return val;
		   } else {
		       printf("----- Empty Stack -----\n");
		       return -1;
		   } 
		}

		// Display the contents of the stack
		void display() {
		    int index = top;

		    if(isEmpty()){
		        printf("---- Empty Stack ----\n");
		    } else {
		        while(index != -1)
		        {
		            printf("%d\n", data[index]);
		            index--;
		        } 
		        printf("\n");  
		    }
		    printf("----------------------\n");
		}
};

