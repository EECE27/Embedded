#include<stdlib.h>
#include<iostream>

#include"stack.h"

using namespace std;

#define MAX_SIZE 100

class Queue2
{
	public:
		Stack st;
    	int front;
    	int back;
    	int itemCount;

    	// Constructor to create a new stack
    	Queue2(){
    		// Create the stack
    		st = Stack();
    		// Size of the queue
    		itemCount = 0;
    	}

    	// Check if queue is empty
		bool isEmpty() {
	   		return st.isEmpty();
		}

		// Check if queue is full
		bool isFull() {
			return st.isFull();
		}
		
		// Return the size of the queue
		int size() {
			return itemCount;
		}

		// Return the value of the first element
		int peek() {
			if (isEmpty()){
				printf("----- Empty Queue -----\n");
		       	return -1;
			}

		   	int x = st.pop();
		   	itemCount--;

		   	if (isEmpty()){
		   		st.push(x);
		   		itemCount++;
		   		return x;
		   	}

		   	// Recursive call
		   	int val = peek();

		   	st.push(x);
		   	itemCount++;

		   	return val;
		}

		// Add an element to the queue
		void enqueue(int val) {
			// Check if queue is not full
			if(!isFull()) {
				st.push(val);
				itemCount++;
			} else {
		    	printf("----- Full Queue -----\n");
		   	}
		}

		// Remove an element from the queue and return the data
		int dequeue() {
			if (isEmpty()){
				printf("----- Empty Queue -----\n");
		       	return -1;
			}

		   	int x = st.pop();
		   	itemCount--;
		   	if (isEmpty())
		   		return x;

		   	// Recursive call
		   	int val = dequeue();

		   	st.push(x);
		   	itemCount++;

		   	return val;
		}

		// Display the contents of the queue
		void display() {

			st.display();

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

