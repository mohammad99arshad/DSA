#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val) : data(val){}
};

bool valid(Node* root, long minVal, long maxVal){
    if(!root) return true;
    if(root->data <= minVal || root->data >= maxVal) return false;
    return valid(root->left, minVal, root->data) && valid(root->right, root->data, maxVal);
}

bool isValidBST(Node* root){
    return valid(root, LONG_MIN, LONG_MAX);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(6);

    bool result = isValidBST(root);
    cout<< result<<endl;
    return 0;
}