#include <iostream>
#include <string>

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



template<typename T>
class Editor {
private:
    Stack<T> mainStack;
    Stack<T> undoStack;

public:
    void addCharacter(const T& character) {
        mainStack.push(character);
        std::cout << "Added character: " << character << std::endl;
    }

    void undo() {
        if (mainStack.isEmpty()) {
            std::cout << "Cannot undo. No characters left." << std::endl;
            return;
        }
        T removedCharacter = mainStack.peek();
        mainStack.pop();
        undoStack.push(removedCharacter);
        std::cout << "Undone character: " << removedCharacter << std::endl;
    }

    void redo() {
        if (undoStack.isEmpty()) {
            std::cout << "Cannot redo. No characters to redo." << std::endl;
            return;
        }
        T redoneCharacter = undoStack.peek();
        undoStack.pop();
        mainStack.push(redoneCharacter);
        std::cout << "Redone character: " << redoneCharacter << std::endl;
    }

    void printContent() {
        std::string content;
        Stack<T> tempStack;
        while (!mainStack.isEmpty()) {
            tempStack.push(mainStack.peek());
            mainStack.pop();
        }

        while (!tempStack.isEmpty()) {
            content += tempStack.peek();
            mainStack.push(tempStack.peek());
            tempStack.pop();
        }

        std::cout << "Current content: " << content << std::endl;
    }
};

int main() {
    Editor<char> textEditor;

    // Adding characters
    textEditor.addCharacter('A');
    textEditor.addCharacter('B');
    textEditor.addCharacter('C');
    textEditor.printContent();

    // Undo
    textEditor.undo();
    textEditor.printContent();

    // Redo
    textEditor.redo();
    textEditor.printContent();

    // Undo and add a new character
    textEditor.undo();
    textEditor.addCharacter('D');
    textEditor.printContent();

    return 0;
}
