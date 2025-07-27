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
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true; // Both nodes are null
    if (!p || !q) return false; // One of the nodes is null

    // Check current node values and recursively check left and right subtrees
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);    
}
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool same = isSameTree(p, q);
    cout << "Are the two trees the same? " << (same ? "Yes" : "No") << endl;

    return 0;
}