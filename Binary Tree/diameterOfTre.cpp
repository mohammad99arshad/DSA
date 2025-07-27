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

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int height(TreeNode *root, int &diameter)
{
    if (root == nullptr)
        return 0;

    int l = height(root->left, diameter);  // height of left subtree
    int r = height(root->right, diameter); // height of right subtree

    diameter = max(diameter, l + r); // Update max diameter so far

    return 1 + max(l, r); // Return height of current subtree
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    return 0;
}
