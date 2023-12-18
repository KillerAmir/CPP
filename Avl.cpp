#include <iostream>
#include <algorithm>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};


int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}


void updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}


int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}


Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    } else {
       
        return root;
    }

    
    updateHeight(root);

   
    int balance = getBalanceFactor(root);

    
    if (balance > 1 && key < root->left->data) {
        return rightRotate(root);
    }

    
    if (balance < -1 && key > root->right->data) {
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

   
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    
    return root;
}


void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

   
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

   
    cout << "AVL Tree after insertions: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
