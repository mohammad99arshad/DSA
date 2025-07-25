// iterative approach

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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>inorder;
    stack<TreeNode*>st;
    TreeNode* node = root;
    while(true){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int>result = inorderTraversal(root);
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}