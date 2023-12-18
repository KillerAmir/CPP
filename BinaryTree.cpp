#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right; 

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int value) 
{
    if (root == nullptr) 
    {
        return new Node(value);
    }

    if (value < root->data)
     {
        root->left = insert(root->left, value);
    } 
    else
     {
        root->right = insert(root->right, value);
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


bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
   
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    int searchValue = 40;
    cout << "Search for " << searchValue << ": " << (search(root, searchValue) ? "Found" : "Not Found") << endl;

    return 0;
}
