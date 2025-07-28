#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, ll>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int size = q.size();
        ll first = q.front().second;
        ll last = q.back().second;
        maxWidth = max(maxWidth, int(last - first + 1));

        while(size--) {
            TreeNode* node = q.front().first;
            int index = q.front().second;
            q.pop();

            if (node->left) {
                q.push({node->left, 2 * index + 1});
            }
            if (node->right) {
                q.push({node->right, 2 * index + 2});
            }
        }
    }
    return maxWidth;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Width of the binary tree: " << widthOfBinaryTree(root) << endl;

    return 0;
}