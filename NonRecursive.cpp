#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}


void nonRecursiveInorderTraversal(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}


void nonRecursivePreorderTraversal(Node* root) {
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        if (current != nullptr) {
            cout << current->data << " ";

          
            s.push(current->right);
            s.push(current->left);
        }
    }
}


void nonRecursivePostorderTraversal(Node* root) {
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();

        if (current != nullptr) {
            
            s2.push(current);

            
            s1.push(current->left);
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        Node* current = s2.top();
        s2.pop();
        cout << current->data << " ";
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

    cout << "Non-Recursive Inorder Traversal: ";
    nonRecursiveInorderTraversal(root);
    cout << endl;

    cout << "Non-Recursive Preorder Traversal: ";
    nonRecursivePreorderTraversal(root);
    cout << endl;

    cout << "Non-Recursive Postorder Traversal: ";
    nonRecursivePostorderTraversal(root);
    cout << endl;

    return 0;
}
