#include <iostream>
#include <vector>

template <typename T>
class ArrayBST {
private:
    std::vector<T> tree; // Holds the elements
    std::vector<bool> present; // Tracks whether an element is present at a position
    int maxSize;

    void inOrder(int index) {
        if (index >= maxSize || !present[index]) return;
        inOrder(2 * index + 1); // Visit left child
        std::cout << tree[index] << " "; // Visit node
        inOrder(2 * index + 2); // Visit right child
    }

public:
    ArrayBST(int size) : maxSize(size) {
        tree.resize(size);
        present.resize(size, false);
    }

    bool insert(T value) {
        int index = 0;
        while (index < maxSize) {
            if (!present[index]) {
                tree[index] = value;
                present[index] = true;
                return true;
            }
            if (value < tree[index]) {
                index = 2 * index + 1; // Move to left child
            } else if (value > tree[index]) {
                index = 2 * index + 2; // Move to right child
            } else {
                return false; // Duplicate value found, insertion failed
            }
        }
        return false; // Tree is full
    }

    void inOrderTraversal() {
        std::cout << "In-order traversal: ";
        inOrder(0);
        std::cout << std::endl;
    }
};

int main() {
    ArrayBST<int> bst(15); // Create a BST with a max size of 15

    // Insert elements
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    bst.inOrderTraversal();

    return 0;
}
