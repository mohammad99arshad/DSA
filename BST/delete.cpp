#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};

Node* findLastRight(Node* root) {
    if (root->right == nullptr) return root;
    return findLastRight(root->right);
}

Node* helper(Node* root) {
    if (root->left == nullptr) return root->right;
    else if (root->right == nullptr) return root->left;

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;
    if (root->data == key) return helper(root);

    Node* curr = root;
    while (curr) {
        if (curr->data > key) {
            if (curr->left != nullptr && curr->left->data == key) {
                curr->left = helper(curr->left);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right != nullptr && curr->right->data == key) {
                curr->right = helper(curr->right);
                break;
            } else {
                curr = curr->right;
            }
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    int key = 3;
    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
