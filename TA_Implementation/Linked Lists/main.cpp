#include<stdlib.h>
#include<iostream>

#include "linkedlist.h"

using namespace std;

int main()
{
	Node* head = nullptr;
	LinkedList LL = LinkedList();

	LL.append(&head, 1);
	LL.append(&head, 2);
	LL.append(&head, 2);
	LL.append(&head, 5);
	LL.append(&head, 5);
	LL.append(&head, 4);

	cout << "Our linked list: \n";
	LL.displayLL(head);
	cout << "---------------------------- \n\n";

	cout << "Adding an element (3) in the middle: \n";
	LL.insertMidElement(head, 3);
	LL.displayLL(head);
	cout << "---------------------------- \n\n";

	// We will assume k < length of the list
	cout << "Removing (k=4) element from the end: \n";
	LL.removeKthNodeFromEnd(head, 4);
	LL.displayLL(head);
	cout << "---------------------------- \n\n";

	cout << "Removing duplicates from unsorted list: \n";
	LL.removeDuplicatesUnsorted(head);
	LL.displayLL(head);
	cout << "---------------------------- \n\n";


	
	return 0;
}