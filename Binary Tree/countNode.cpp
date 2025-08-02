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

int countNodes(TreeNode *root){
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);

}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int totalNodes = countNodes(root);
    cout << "Total number of nodes in the binary tree: " << totalNodes << endl;
    return 0;
}