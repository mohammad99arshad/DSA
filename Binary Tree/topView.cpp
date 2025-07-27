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
vector<int> topView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> topNodes; // To store the first node at each horizontal distance
    queue<pair<TreeNode*, int>> q; // Pair of node and its horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, line] = q.front();
        q.pop();

        // If this is the first time we are visiting this horizontal distance
        if (topNodes.find(line) == topNodes.end()) {
            topNodes[line] = node->val;
        }

        // Push left and right children with updated horizontal distances
        if (node->left) q.push({node->left, line - 1});
        if (node->right) q.push({node->right, line + 1});
    }

    // Collecting the results from the map in sorted order of horizontal distances
    for (const auto& [line, val] : topNodes) {
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

    vector<int> result = topView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}