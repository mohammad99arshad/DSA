#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};

Node* buildBST(Node* root, int ele) {
    if (!root) return new Node(ele);
    if (root->data > ele) {
        root->left = buildBST(root->left, ele);
    } else {
        root->right = buildBST(root->right, ele);
    }
    return root;
}

Node* bstFromPreorder(vector<int>& pre) {
    Node* root = nullptr;
    for (auto x : pre) {
        root = buildBST(root, x);  
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    Node* root = bstFromPreorder(pre); 
    inorder(root);  
    return 0;
}
