#include<stdlib.h>
#include<iostream>

using namespace std;

class Node
{
public:
	// Content of the node
	int data;
	Node* next;

	// Constructor to create a new node
	Node(int new_data){
		data = new_data;
		next = nullptr;
	};
};

class LinkedList
{
public:

	// Add a new node at the end of a linked list
	void append(Node** head, int data){

		// Check if the linked list is empty
		if(*head == nullptr){
			*head = new Node(data);
			return;
		}

		// Create a temp pointer to preserve the head
		Node* temp = *head;
		// Traverse the linked list till the last node is reached
		while (temp->next != nullptr){
			temp = temp->next;
		}

		// Let the last node point to the new data after being created
		temp->next = new Node(data);
	};

	// Display the content of a linked list
	void displayLL(Node* head){

		// Create a temp pointer to preserve the head
		Node* temp = head;

		// Traverse the linked list and print the content of each node
		while(temp->next != nullptr){
			cout << temp->data << " -> ";
			temp = temp->next;
		}

		cout << temp->data << "\n";
	};

	// Find the middle element of a linked list
	Node* findMiddleElement (Node* head){

		// Create a temp pointer that points to the first node
		Node* first = head;
		// Create a temp pointer that points to the second node
		Node* second = head->next;

		// Traverse the linked list till its end
		while(second != nullptr && second->next != nullptr){
			// The first pointer increments in steps of size 1
			first = first->next;
			// The second pointer increments in steps of size 2
			second = second->next->next;
		}

		// The first pointer now points to the middle node of the list
		return first;
	};

	// Insert a node in the middle of a linked list
	void insertMidElement(Node* head, int data){
		// Get a pointer to the middle node of the list
		Node* midElement = findMiddleElement(head);

		// Create the new node and insert it in the middle
		Node* newNode = new Node(data);
		newNode->next = midElement->next;
		midElement->next = newNode;
	};

	// Find the kth node from the end of a linked list
	Node* findKthNodeFromEnd(Node* head, int k)
	{
		// Create temp pointers that point to the first node
		Node* first = head;
        Node* second = head;

        // Move the second pointer till it points to (k+1) node
        for (int i = 0; i < k + 1; i++)
        {
            second = second->next;
        }

        // Traverse the linked list till its end
        while (second != NULL)
        {
        	// The two pointers increment in steps of size 1
            first = first->next;
            second = second->next;
        }
        
        // The first pointer now points to the (k+1) node
        // from the end of the list
        return first;

	};

	// Remove the kth node from the end of a linked list
	void removeKthNodeFromEnd(Node* head, int k)
	{
	    // Get the pointer pointing to the kth+1 node from the end of LL
	    Node* k1NodePtr = findKthNodeFromEnd(head, k);

	    // Create a duplicate of kth node
	    Node* dup = k1NodePtr->next;
	    // The kth+1 from the end points to kth-1 from the end
	    k1NodePtr->next = k1NodePtr->next->next;
	    // Delete kth node
	    delete(dup);
	};

	// Remove duplicates from a sorted linked list
	void removeDuplicatesSorted(struct Node* head)
	{
		// Create temp pointer that points to the first node
	    Node* tmp = head;

	    // Traverse the linked list till its end
	    while(tmp != NULL && tmp->next != NULL){
	    	// If the data of next node is the same
	        if(tmp->data == tmp->next->data){
	        	// Create a duplicate of ith+1 node
	            Node* dup = tmp->next;
	            // The ith node points to ith+2 node
	            tmp->next = tmp->next->next;
	            delete(dup);
	        }
	        // If the data of next node is not the same 
	        else 
	        {
	            tmp = tmp->next;
	        }
	    }
	};

	// Remove duplicates from an unsorted linked list
	void removeDuplicatesUnsorted(Node* head)
	{
		// Create temp pointers
        Node *tmp1, *tmp2, *dup;

        // Let tmp1 points to the first node
        tmp1 = head;

        // Traverse the list using tmp1
        while (tmp1 != NULL && tmp1->next != NULL)
        {
            tmp2 = tmp1;
            
            // Traverse the list using tmp2
            while (tmp2->next != NULL)
            {
            	// If a duplicate was found
                if (tmp1->data == tmp2->next->data)
                {
                    dup = tmp2->next;
                    tmp2->next = tmp2->next->next;
                    delete(dup);
                }
                else
                {
                    tmp2 = tmp2->next;
                }
            }

            // tmp1 increments 1 for the next iteration
            tmp1 = tmp1->next;
        }  
	};

};
