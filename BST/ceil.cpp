#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data; 
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val){}
};

int findCeil(Node* root, int key){
    int ceilVal = -1;
    while(root){
        if(root->data == key){
            ceilVal = root->data;
            return ceilVal;
        }
        if(key > root->data){
            root = root->right;
        }else{
            ceilVal = root->data;
            root = root->left;
        }
    }
    return ceilVal;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right->right = new Node(9);
    
    int key = 8;
    int result = findCeil(root, key);
    cout << "Ceil of " << key << " is: " << result << endl;
    return 0;
}