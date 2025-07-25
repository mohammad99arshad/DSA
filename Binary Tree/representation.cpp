#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;

    tree(int val){
        data = val;
        left = right = nullptr;
    }
};

int main(){
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->right = new tree(5);
    return 0;
}
