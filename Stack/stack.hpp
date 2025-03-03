#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class stack
{
    private:
        T max = 100;
        int top;

    public:
        stack();
        bool push(T);
        T pop(void);
        T peek(void);
};

#endif