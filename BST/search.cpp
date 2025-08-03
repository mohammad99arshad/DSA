#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left =nullptr;
    Node* right = nullptr;
    Node(int val) : data(val){}
};

Node* search(Node* root, int key){
    while(root != nullptr && root->data != key){
        root = key < root->data ? root->left : root->right;
    }
    return root;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    int key = 2;
    Node* result = search(root, key);
    if(result != nullptr){
        cout << "Node with key " << key << " found: " << result->data << endl;
    } else {
        cout << "Node with key " << key << " not found." << endl;
    }
    return 0;
}