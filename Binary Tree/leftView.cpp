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

vector<int>leftView(TreeNode* root){
    vector<int>result;
    if(!root) return result;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            // If it's the first node of this level, add it to the result
            if(i == 0) {
                result.push_back(node->val);
            }
            // Push left and right children into the queue
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return result;
}


int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = leftView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}