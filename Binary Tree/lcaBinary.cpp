#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == p->val)
    {
        return p;
    }
    if (root->val == q->val)
    {
        return q;
    }

    TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns == nullptr && rightAns == nullptr)
    {
        return nullptr;
    }
    else if (leftAns != nullptr && rightAns == nullptr)
    {
        return leftAns;
    }
    else if (leftAns == nullptr && rightAns != nullptr)
    {
        return rightAns;
    }
    return root;
}

int main(){

    // Example usage:
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *p = root->left; // Node with value 5
    TreeNode *q = root->left->right->right; // Node with value 4

    TreeNode *lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else { 
        cout << "Lowest Common Ancestor not found." << endl;
    }
    return 0;
}