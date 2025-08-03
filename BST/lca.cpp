#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val) : data(val) {}
};

Node* lca(Node* root, Node* p, Node* q) {
    if (!root) return NULL;
    int curr = root->data;

    if (curr < p->data && curr < q->data)
        return lca(root->right, p, q);
    if (curr > p->data && curr > q->data)
        return lca(root->left, p, q);
    return root;
}

// helper to find a node with given value in BST
Node* findNode(Node* root, int val) {
    if (!root || root->data == val) return root;
    if (val < root->data) return findNode(root->left, val);
    return findNode(root->right, val);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->right->left = new Node(12);
    root->left->right = new Node(7);
    root->left->left = new Node(1);

    int p_val = 1;
    int q_val = 7;

    Node* p = findNode(root, p_val);
    Node* q = findNode(root, q_val);

    Node* result = lca(root, p, q);
    if (result)
        cout << "LCA of " << p_val << " and " << q_val << " is: " << result->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
