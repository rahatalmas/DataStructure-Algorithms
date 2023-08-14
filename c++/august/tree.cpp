#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node*left;
        Node*right;
        Node(int data);
    friend class BinaryTree;
};
Node::Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

class Bst{
    private:
        //Node * root = NULL;
    public:
        Node * root = NULL;
        void insertNode(int data,Node *temp);
        void insert(Node * temp,int data);
        void printTree();
};

void Bst::insert(Node *temp,int data){

}

void Bst::insertNode(int data){
    Node * new_node = new Node(data);
    if(this->root == NULL){
        this->root = new_node;
        return;
    }
    Node * temp = this->root;
    if(this->root->data > data){
        insert(this->root->left,data);
    }
   
}


int main(){
    Bst tree;
    tree.insertNode(5);
}