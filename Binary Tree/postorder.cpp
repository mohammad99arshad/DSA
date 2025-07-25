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

void postorder(TreeNode* node, vector<int>& result) {
    if (node == nullptr) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorder(root, result);
    return result;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int>result = postorderTraversal(root);
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}