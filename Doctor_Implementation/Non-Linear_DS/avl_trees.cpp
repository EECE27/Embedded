#include <iostream>
#include <algorithm>

using namespace std;

class AVLNode {
public:
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    AVLNode* root;

    AVLTree() : root(nullptr) {}

    int height(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {
		//cout<<"rotating right"<<endl;
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) +1;
		x->height = std::max(height(x->left), height(x->right)) + 1;
		return x;
}

AVLNode* rotateLeft(AVLNode* x) {
	//cout<<"rotating left"<<endl;
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* insert(AVLNode* node, int key) {
    if (node == nullptr) {
        return new AVLNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left,key);
	} else if (key > node->key) {
	node->right = insert(node->right, key);
	} else {
	// Duplicate keys are not allowed
	return node;
	}
	
	node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1) {
        if (key < node->left->key) {
			cout<<"rotate right, value="<<key<<endl;
            return rotateRight(node);
        } else {
			cout<<"rotate left-right, value="<<key<<endl;
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balance < -1) {
        if (key > node->right->key) {
			cout<<"rotate left, value="<<key<<endl;
            return rotateLeft(node);
		} else {
		cout<<"rotate right-left, value="<<key<<endl;
		node->right = rotateRight(node->right);
		return rotateLeft(node);
		}
		}
		
		return node;
}

void insert(int key) {
    root = insert(root, key);
}

};

int main() {
	AVLTree tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(25);

	// The tree should now be balanced.

	return 0;
}




		
