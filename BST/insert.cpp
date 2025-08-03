#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val) : data(val) {}
};

Node *insertNode(Node *root, int val)
{
    if (!root)
        return new Node(val);
    Node *curr = root;
    while (true)
    {
        if (curr->data <= val)
        {
            if (curr->right != nullptr)
                curr = curr->right;
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
        else
        {
            if (curr->left != nullptr)
                curr = curr->left;
            else
            {
                curr->left = new Node(val);
                break;
            }
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    int val = 5;
    root = insertNode(root, val);

    cout << "Inorder after deletion: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
