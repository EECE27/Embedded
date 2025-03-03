#include "stack.hpp"

stack::stack()
{
    top = 0;
}

bool stack::push(T var)
{
    if(top >= max)
    {
        std::cout << "Stack Overflow";
        return FASLE;
    }
}