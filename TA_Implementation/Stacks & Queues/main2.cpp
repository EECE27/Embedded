#include<stdlib.h>
#include<iostream>

#include "queue2.h"

using namespace std;


int main()
{
	Queue2 qu = Queue2();

	cout << "Our queue: \n";
	qu.display();
	cout << "\n";

	cout << "Trying the enqueue function: \n";
	qu.enqueue(1);
	qu.display();
	qu.enqueue(2);
	qu.display();
	qu.enqueue(3);
	qu.display();
	qu.enqueue(4);
	qu.display();
	qu.enqueue(5);
	qu.display();
	qu.enqueue(6);
	qu.display();
	qu.enqueue(7);
	qu.display();
	cout << "\n";

	cout << "Trying the peek function: \n";
	int x = qu.peek();
	cout << x << "---\n" ;
	x = qu.peek();
	cout << x << "---\n" ;
	qu.display();
	cout << "\n";

	cout << "Trying the dequeue function: \n";
	x = qu.dequeue();
	cout << x << "---\n" ;
	x = qu.dequeue();
	cout << x << "---\n" ;
	qu.display();
	cout << "\n";

	cout << "Trying the reverse function: \n";
	qu.reverse();
	qu.display();
	cout << "\n";

	cout << "Trying the reverse first (k=3) items function: \n";
	qu.reverseFirstKItems(3);
	qu.display();
	cout << "\n";
	
	return 0;
}