#include<stdlib.h>
#include<iostream>

#include"stack.h"

using namespace std;

#define MAX_SIZE 100

class Queue
{
	public:
		int data[MAX_SIZE];
    	int front;
    	int back;
    	int itemCount;

    	// Constructor to create a new stack
    	Queue(){
    		// Index for the first element in the queue
    		front = 0;
    		// Index for the last element in the queue
    		back = -1;
    		// Size of the queue
    		itemCount = 0;
    	}

    	// Check if queue is empty
		bool isEmpty() {
	   		return itemCount == 0;
		}

		// Check if queue is full
		bool isFull() {
			return itemCount == MAX_SIZE;
		}
		
		// Return the size of the queue
		int size() {
			return itemCount;
		}

		// Return the value of the first element
		int peek() {
			if (!isEmpty())
	        	return data[front];
	        else
	        	return -1;
		}

		// Add an element to the queue
		void enqueue(int val) {
			// Check if queue is not full
			if(!isFull()) {
				// Check if back is pointing at the end of the array
				if(back == MAX_SIZE-1)
					back = -1;

				// Pre-increment the index
				data[++back] = val;
				itemCount++;
			} else {
		    	printf("----- Full Queue -----\n");
		   	}
		}

		// Remove an element from the queue and return the data
		int dequeue() {
		   int val;

		   // Check if queue is not empty
		   if(!isEmpty()) {    
		       val = data[front++];

		       // Check if front is pointing at the end of the array
				if(front == MAX_SIZE)
					front = 0;

				itemCount--;
		       // Return the data
		       return val;
		   } else {
		       printf("----- Empty Queue -----\n");
		       return -1;
		   } 
		}

		// Display the contents of the queue
		void display() {
		    int i = 0;
		    int tmp = front;

		    if(isEmpty()){
		        printf("---- Empty Queue ----\n");
		    } else {
		        while(tmp+i != back+1)
		        {
		        	if (tmp+i < MAX_SIZE)
		            	printf("%d ", data[tmp+i]);
		            else
		            {
		            	tmp = 0;
		            	i = 0;
		            	printf("%d ", data[tmp+i]);
		            } 
		            	
		            i++;
		        } 
		        printf("\n");  
		    }
		    printf("Number of elements in the queue is: %d\n", size());
		    printf("----------------------\n");
		}

		void reverseFirstKItems(int k){
		    Stack st = Stack();

		    if(isEmpty() || k > itemCount || k <= 0) {
		        return;
		    }

		    /* Push the first K elements into a Stack*/
		    for (int i = 0; i < k; i++)
		    {
		        st.push(dequeue());
		    }

		    /* Enqueue the contents of stack at the back of the queue*/
		    while(!st.isEmpty()){
		        enqueue(st.pop());
		    }

		    /* Remove the remaining elements and enqueue them at the end of the Queue*/
		    for (int i = 0; i < size()-k; i++)
		    {
		        enqueue(dequeue());
		    }
		}

		void reverse(){
		    Stack st = Stack();

		    if(isEmpty()) {
		        return;
		    }

		    /* Push the queue elements into a Stack*/
		    while(!isEmpty())
		    {
		        st.push(dequeue());
		    }

		    /* Enqueue the contents of stack at the back of the queue*/
		    while(!st.isEmpty()){
		        enqueue(st.pop());
		    }

		}

};

