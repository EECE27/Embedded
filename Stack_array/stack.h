#ifndef STACK_H
#define STACK_H

template <typename T>
class stack
{
    private:
        static const int max = 100;
        T arr[max];
        int top;

    public:
        
        stack()
        {
            top = 0;    // Start with empty stack
            // for(int i = 0; i < max; i++)
            //     arr[i] = 0;
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
                cout << "Stack Underflow";
                return 0;
            }

            T return_val = arr[--top];

            return return_val;
        }

        T peek(void)
        {
            if(top == 0)
            {
                cout << "Stack Underflow";
                return 0;
            }

            return arr[top - 1];   
        }


};

#endif