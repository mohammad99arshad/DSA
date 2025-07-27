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
int heightTree(TreeNode* root){
    if(root == nullptr) return -1;
    int l = heightTree(root->left);
    int r = heightTree(root->right);
    return 1+max(l,r);
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = heightTree(root);
    cout << "Height of the tree: " << height << endl;
    
    return 0;
}