#include <iostream>
#include <stdexcept>

template<typename T, int size>
class ArrayQueue {
private:
    T arr[size];
    int front;
    int rear;
    int count;

public:
    ArrayQueue() : front(0), rear(-1), count(0) {}

    void enqueue(const T& item) {
        if (isFull()) {
            throw std::out_of_range("Queue is full");
        }
        rear = (rear + 1) % size;
        arr[rear] = item;
        count++;
        std::cout<<"front = "<< front<<" ,rear = "<<rear<<std::endl;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T item = arr[front];
        front = (front + 1) % size;
        count--;
        std::cout<<"front = "<< front<<" ,rear = "<<rear<<std::endl;
        return item;
        
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }
};

int main() {
    ArrayQueue<int, 5> queue;

    try {
        // Enqueue elements until the queue is full to demonstrate exception handling.
        for (int i = 0; i < 6; ++i) {
            queue.enqueue(i);
            std::cout << "Enqueued: " << i << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Dequeue elements and then attempt one more dequeue to trigger an exception.
        while (true) {
            int front = queue.dequeue();
            std::cout << "Dequeued: " << front << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        // Enqueue elements until the queue is full to demonstrate exception handling.
        for (int i = 0; i < 6; ++i) {
            queue.enqueue(i);
            std::cout << "Enqueued: " << i << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
