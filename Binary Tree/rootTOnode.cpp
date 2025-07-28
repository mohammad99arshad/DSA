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

bool getpath(TreeNode* root, int target, vector<int>& path) {
    if (!root) return false; // Base case: if the node is null, return false

    path.push_back(root->val); // Add the current node's value to the path

    // If the current node is the target, return true
    if (root->val == target) {
        return true;
    }

    // Recursively search in the left and right subtrees
    if (getpath(root->left, target, path) || getpath(root->right, target, path)) {
        return true; // If found in either subtree, return true
    }
    
    // If not found in either subtree, remove the current node from the path and return false
    path.pop_back();
    return false;
}

vector<int>rootToNode(TreeNode* root, int target) {
    vector<int> path; // Vector to store the path from root to the target node
    getpath(root, target, path);
    return path;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int target = 4;
    vector<int> path = rootToNode(root, target);
    cout << "Path from root to node " << ": ";
    for (int val : path) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}


