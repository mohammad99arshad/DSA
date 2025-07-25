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

void preorder(TreeNode* node, vector<int>& result) {
    if (node == nullptr) return;
    result.push_back(node->val);
    preorder(node->left, result);
    preorder(node->right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int>result = preorderTraversal(root);
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}