#include <iostream>
#include <queue>

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
    Node<T>* root;

    BinarySearchTree() : root(nullptr) {}

    // Function to insert a new node with the given data
    void insert(T data) {
        root = insertRec(root, data);
    }

    // Function to perform in-order traversal
    void inOrderTraversal() {
        std::cout << "In-order Traversal: ";
        inOrder(root);
        std::cout << std::endl;
    }

    // Function to perform pre-order traversal
    void preOrderTraversal() {
        std::cout << "Pre-order Traversal: ";
        preOrder(root);
        std::cout << std::endl;
    }

    // Function to perform post-order traversal
    void postOrderTraversal() {
        std::cout << "Post-order Traversal: ";
        postOrder(root);
        std::cout << std::endl;
    }

   

private:
    // Recursive function to insert a new node into the BST
    Node<T>* insertRec(Node<T>* node, T data) {
        if (node == nullptr) {
            return new Node<T>(data);
        }
        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else if (data > node->data) {
            node->right = insertRec(node->right, data);
        }
        return node;
    }

    // Utility function for in-order traversal
    void inOrder(Node<T>* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Utility function for pre-order traversal
    void preOrder(Node<T>* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Utility function for post-order traversal
    void postOrder(Node<T>* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }

    // Utility function for level-order traversal
};

// Example usage
int main() {
    BinarySearchTree<int> bst;

    // Inserting nodes
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform traversals
    bst.inOrderTraversal();
    bst.preOrderTraversal();
    bst.postOrderTraversal();
    // bst.levelOrderTraversal();

    return 0;
}
