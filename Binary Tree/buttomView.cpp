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

vector<int> buttomView(TreeNode* root){
    vector<int> result;
    if (!root) return result;

    map<int, int> buttomElements;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, line] = q.front();
        q.pop();
         // Update the bottom view with the current node's value
        buttomElements[line] = node->val;
        // Push left and right children with updated horizontal distances

        if (node->left) q.push({node->left, line - 1});
        if (node->right) q.push({node->right, line + 1});
    }

    for (const auto& [line, val] : buttomElements) {
        result.push_back(val);
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

    vector<int> result = buttomView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}