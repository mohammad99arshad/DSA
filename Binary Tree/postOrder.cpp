// iterative approach with 2 stack>

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

vector<int>postorderTraversal(TreeNode* root){
    stack<TreeNode*>st1, st2;
    vector<int>postOrder;
    if(root == nullptr) return postOrder;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr){
            st1.push(root->left);
        }
        if(root->right != nullptr){
            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        postOrder.push_back(st2.top()->val);
        st2.pop();
    }
    return postOrder;
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