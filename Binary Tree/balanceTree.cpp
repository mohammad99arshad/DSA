#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

int heightTree(TreeNode* root) {
    if (root == nullptr) return 0; // Fix: height of empty tree is 0
    int l = heightTree(root->left);
    if (l == -1) return -1; // Left subtree unbalanced
    int r = heightTree(root->right);
    if (r == -1) return -1; // Right subtree unbalanced
    if (abs(l - r) > 1) return -1; // Current node unbalanced
    return 1 + max(l, r);
}

bool isBalanced(TreeNode* root) {
    return heightTree(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    bool balanced = isBalanced(root);
    cout << "Is the tree balanced? " << (balanced ? "Yes" : "No") << endl;

    return 0;
}
