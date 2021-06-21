#include<bits/stdc++.h>
using namespace std;
struct Tree{
    int data;
    struct Tree * left;
    struct Tree * right;
};

Tree * addNode(Tree * root , int x){
    if(root == NULL){
        root->data=x;
    }
    if(root->data <= x){
        addNode(root->right,x);
    }else{
        addNode(root->left,x);
    }
    return root;
}
void printInorder(Tree * root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data;
    printInorder(root->right);
}
int main(){
    Tree *root=NULL;
    root=addNode(root,15);
    printInorder(root);
}