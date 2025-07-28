#include<bits/stdc++.h>
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

bool isSymmetric(TreeNode* root){
    if(!root) return true; // An empty tree is symmetric
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    
    while(!q.empty()){
        TreeNode* leftNode = q.front();
        q.pop();
        TreeNode* rightNode = q.front();
        q.pop();
        
        // If both nodes are null, continue to the next pair
        if(!leftNode && !rightNode) continue;
        
        // If one is null and the other is not, or values are different, it's not symmetric
        if(!leftNode || !rightNode || leftNode->val != rightNode->val) {
            return false;
        }
        
        // Push children in reverse order for symmetry check
        q.push(leftNode->left);
        q.push(rightNode->right);
        q.push(leftNode->right);
        q.push(rightNode->left);
    }
    
    return true; // If we finish the loop without issues, the tree is symmetric
}


int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    // You can add more nodes to create a symmetric tree for testing
    bool result = isSymmetric(root);
    cout<< (result ? "The tree is symmetric." : "The tree is not symmetric.") << endl;
    return 0;
}