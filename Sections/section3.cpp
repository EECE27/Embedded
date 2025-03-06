#include <iostream>

    /*Stacks & Queues*/

struct node;
typedef node* link;
struct data
{
    int data;
    link next;
};

template <typename T, int max> // Non-type paramter to specify the size
class stack
{
    private:
        T arr[max];
        int top;

    public:
        
        stack()
        {
            top = 0;    // Start with empty stack
            //* Increment After logic -> points to the last empty location rather than the last filled locations
            //* for Increment before -> top = -1, where -1 segnifies an empty stack
        }

        bool push(T var)
        {
            if(top >= max)
            {
                std::cout << "Stack Overflow";
                return false;
            }

            arr[top++] = var;
            return true;
        }

        T pop(void)
        {
            if(top == 0)
            {
                std::cout << "Stack Underflow";
                return 0;
            }

            T return_val = arr[--top];

            return return_val;
        }

        T peek(void)
        {
            if(top == 0)
            {
                std::cout << "Stack Underflow";
                return 0;
            }

            return arr[top - 1];   
        }


};

class queueLinkedd
{
    link head;
    link tail;

    public:

    queueLinked()
    {

    }
};

int main(void)
{
    stack myStack<int, 100>;

    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    std::cout << myStack.pop();
    std::cout << myStack.pop();
    std::cout << myStack.pop();

    std::cout << myStack.peak();


}

// Q1
/**
 * Stack:
 * push 8, 9, 7
 * pop
 * push 10 1
 * pop
 * peek
 * peek
 * push 11
 * pop
 * 
 * Stack: 8,9,7
 *        8,9
 *        8,9,10,1
 *        8,9,10
 *        8,9,10,11
 *        8,9,10
 */

 /***
  * Q2:
  * enq 8 9 7
  * dequeue
  * enqueue 10 1
  * dequeue
  * peek
  * oeek
  * enqueue 11
  * dequeue
  * 
  * 8 9 7
  * 9 7
  * 9 7 10 1
  * 7 10 1
  * 7
  * 7
  * 7 10 1 11
  * 10 1 11     
  * /
*/

//*Q3:

/**
 * 
 */