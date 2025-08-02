// construct binary tree from inorder and preorder traversal

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
TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd, int preStart, int preEnd){

}

 int main(){
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    int n = inorder.size();
    
    TreeNode *root = buildTree(inorder, preorder, 0, n-1, 0, n-1);

    return 0;
 }
