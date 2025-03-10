#include <iostream>
#include <algorithm> // For std::copy

template<typename T>
class Stack {
private:
    T* data;          // Dynamic array for the stack elements
    size_t capacity;  // Current capacity of the array
    size_t topIndex;  // Index of the top element in the stack

    // Ensure the stack has enough capacity to hold more elements
    void ensureCapacity() {
        if (topIndex >= capacity) {
            // Grow: Double the capacity or allocate 1 if no capacity
            size_t newCapacity = capacity ? capacity * 2 : 1;
            T* newData = new T[newCapacity];
            std::copy(data, data + capacity, newData);
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
    }

public:
    Stack() : data(nullptr), capacity(0), topIndex(0) {}

    ~Stack() {
        delete[] data;
    }

    // Push a new element onto the stack
    void push(const T& value) {
        ensureCapacity();
        data[topIndex++] = value;
    }

    // Pop the top element from the stack
    void pop() {
        if (!isEmpty()) {
            --topIndex;
        }
    }

    // Get the top element of the stack
    T top() const {
        if (!isEmpty()) {
            return data[topIndex - 1];
        }
        throw std::out_of_range("Stack is empty");
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex == 0;
    }

    // Get the number of elements in the stack
    size_t size() const {
        return topIndex;
    }
};

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl; // Should print 30

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Should print 20

    std::cout << "Stack size: " << stack.size() << std::endl; // Should print 2

    return 0;
}


/*Key Components
Dynamic Array: data is a pointer to a dynamically allocated array that stores the stack elements.

Capacity Management: The ensureCapacity method checks if the stack needs to grow before adding a new element. It doubles the capacity each time the array is full, minimizing the number of allocations.

Top Index: topIndex keeps track of the current top of the stack (and effectively, the stack's size). Elements are added and removed from the "top" of the array.

Push and Pop Operations: push adds elements to the top of the stack, and pop removes them. Note that pop doesn't delete the element; it just decrements the topIndex.

Top Element Access: top returns the current top element of the stack. It throws an exception if the stack is empty, as there's no element to return.
*/