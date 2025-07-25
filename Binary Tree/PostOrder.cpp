// iterative approach with 1 stack

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postorder;
    if (root == nullptr)
        return postorder;

    stack<TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *lastVisited = nullptr;

    while (!st.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *peek = st.top();
            if (peek->right != nullptr && lastVisited != peek->right)
            {
                curr = peek->right;
            }
            else
            {
                postorder.push_back(peek->val);
                lastVisited = peek;
                st.pop();
            }
        }
    }
    return postorder;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int> result = postorderTraversal(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}