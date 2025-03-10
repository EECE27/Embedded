#include <iostream>

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    void push(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return T();
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int size() const {
        return count;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Top element: " << s.peek() << std::endl;
    std::cout << "Stack size: " << s.size() << std::endl;

    s.pop();

    std::cout << "Top element after pop: " << s.peek() << std::endl;
    std::cout << "Stack size after pop: " << s.size() << std::endl;

    return 0;
}
