#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};
void inorder(Node* root, vector<int>& arr){
    if(!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
bool twoSum(Node* root, int k){
    vector<int>result;
    inorder(root, result);
    int start = 0;
    int end = result.size()-1;
    while(start<end){
        int sum = result[start] + result[end];
        if(sum == k) return true;
        if(sum < k){
            start++;
        }else{
            end--;
        }
    }
    return false;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    int k = 8;
    bool result = twoSum(root, k);
    cout<<result<<endl;
    return 0;
}