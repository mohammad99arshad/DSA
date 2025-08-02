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

// Using unordered_map<TreeNode*, TreeNode*> to store parent pointers
unordered_map<TreeNode *, TreeNode *> parent;

// Corrected inOrder traversal to populate parent map
void inOrder(TreeNode *root)
{
    if (!root)
        return;

    // Populate parent for left child
    if (root->left != nullptr)
    {
        parent[root->left] = root;
        inOrder(root->left);
    }
    // Populate parent for right child
    if (root->right != nullptr)
    {
        parent[root->right] = root;
        inOrder(root->right);
    }
}

// Corrected BFS to find nodes at distance k
void BFS(TreeNode *target, int k, vector<int> &result)
{
    queue<TreeNode *> q;
    q.push(target);
    // Using unordered_set<TreeNode*> for visited nodes
    unordered_set<TreeNode *> visited;
    visited.insert(target);

    // BFS level by level
    while (!q.empty())
    {
        int n = q.size();
        // If k reaches 0, all nodes in the current queue are at distance k
        if (k == 0)
            break;

        for (int i = 0; i < n; ++i)
        { // Iterate through current level nodes
            TreeNode *curr = q.front();
            q.pop();

            // Check left child
            if (curr->left != nullptr && visited.find(curr->left) == visited.end())
            { // Check if not visited
                q.push(curr->left);
                visited.insert(curr->left);
            }
            // Check right child
            if (curr->right != nullptr && visited.find(curr->right) == visited.end())
            { // Check if not visited
                q.push(curr->right);
                visited.insert(curr->right);
            }
            // Check parent
            if (parent.count(curr) && visited.find(parent[curr]) == visited.end())
            { // Check if parent exists and not visited
                q.push(parent[curr]);
                visited.insert(parent[curr]);
            }
        }
        k--; // Decrement k after processing each level
    }

    // Add remaining nodes in the queue to the result
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        result.push_back(temp->val);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> result;
    inOrder(root);          // Build parent map
    BFS(target, k, result); // Perform BFS to find nodes at distance k
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Let's find all nodes at distance 2 from node with value 5
    TreeNode *target = root->left; // node with value 5
    int k = 2;
    vector<int> res = distanceK(root, target, k);
    cout << "Nodes at distance " << k << " from target " << target->val << ": ";
    for (int v : res)
        cout << v << " ";
    cout << endl;
    return 0;
}