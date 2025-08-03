#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val){} 
};

int findFloor(Node* root, int key){
    int floorVal = INT_MIN;
    while(root){
        if(root->data == key){
            floorVal = root->data;
            return floorVal;
        }
        if(key < root->data){
            root = root->left;
        }else{
            floorVal = root->data;
            root = root->right;
        }
    }
    return floorVal;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(6);

    int key = 7;
    int result = findFloor(root, key); 
    cout<<"floor of "<<key<< " is "<<result<<endl;
    return 0;
}