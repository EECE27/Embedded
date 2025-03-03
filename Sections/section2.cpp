#include <iostream>
#include <stdlib.h>


using std::cout, std::endl;

template <typename type>
class linkedList
{
    private:
        struct node
        typedef node* link;
        struct node
        {
            type data;
            link next;

            node(type new_data)
            {
                data = new_data;
                next = nullptr;
            }
        };

        link head, current, tail;

    public:

        void append(type new_data)
        {
            
        }
        
        link findMiddle()
        {
            link first = head;
            link second = head->next;

            while((second != nullptr) && (second->next != nullptr))
            {
                first = first->next;
                second = second->next->next;
            }

            return first;
        }
        
    
}

int main(void)
{

}