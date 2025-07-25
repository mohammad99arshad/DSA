// bfs : goes level by level

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

vector<vector<int>>levelOrder(TreeNode* root){
    vector<vector<int>>ans;
    if(root == nullptr) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        for(int i=0; i<q.size(); i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);
    for (const auto& level : result) {
        for (int num : level) {
            cout << num << " ";
        }
    }
    cout<<endl;
    return 0;
}