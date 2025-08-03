#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val) : data(val){}
};
void inorder(Node* root, vector<int>& result){
    if(!root) return; 
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

int kthSmallest(Node* root, int k){
    vector<int>result;
    inorder(root, result);
    return result[k-1];
}
int main(){
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->left->right = new Node(2);
    int k = 2;
    int result = kthSmallest(root, k);
    cout<<result<<endl;
    return 0;
}