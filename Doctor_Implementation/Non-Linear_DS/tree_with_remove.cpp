#include <iostream>

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

    // Function to remove a node with the given data
    void remove(T data) {
        root = removeRec(root, data);
    }

    // Other traversal functions would remain unchanged
  // F1unction to perform in-order traversal
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

    // Function to perform level-order traversal
    void levelOrderTraversal() {
        std::cout << "Level-order Traversal: ";
        levelOrder(root);
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

    // Recursive function to remove a node
    Node<T>* removeRec(Node<T>* node, T data) {
        if (node == nullptr) {
            return node;
        }

        // If the data to be deleted is smaller than the root's data,
        // then it lies in the left subtree
        if (data < node->data) {
            node->left = removeRec(node->left, data);
        }
        // If the data to be deleted is greater than the root's data,
        // then it lies in the right subtree
        else if (data > node->data) {
            node->right = removeRec(node->right, data);
        }
        // if data is same as node's data, then this is the node
        // to be deleted
        else {
            // node with only one child or no child
            if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node<T>* temp = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = removeRec(node->right, temp->data);
        }
        return node;
    }

    // Function to find the smallest node in a subtree
    Node<T>* minValueNode(Node<T>* node) {
        Node<T>* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
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
    void levelOrder(Node<T>* node) {
        if (!node) return;
        std::queue<Node<T>*> queue;
        queue.push(node);

        while (!queue.empty()) {
            Node<T>* temp = queue.front();
            queue.pop();
            std::cout << temp->data << " ";

            if (temp->left) {
                queue.push(temp->left);
            }
            if (temp->right) {
                queue.push(temp->right);
            }
        }
    }
};

// Example usage would remain unchanged

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

    // Remove nodes
    bst.remove(70);  // Example of removing a node with two children

    // Perform in-order traversal to see the result
    bst.inOrderTraversal();

    return 0;
}
