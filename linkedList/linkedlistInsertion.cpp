#include<bits/stdc++.h>
using namespace std;
struct Node{
   int data;
   Node * next;
};

Node * createNode(int x){
    Node * new_node = new Node();
    new_node->data=x;
    new_node->next =NULL;
    return new_node;
}

void insertHead(Node ** head_ref,int x){
    Node * new_node = createNode(x);
    new_node -> data = x;
    new_node -> next = *head_ref;
    *head_ref = new_node;
}

void insertTail(Node ** head_ref,int x){
    Node * new_node = createNode(x);
    Node * last = *head_ref;
    if(last -> next == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void insertGivenPosition(Node *prev, int x){
    Node * new_node = createNode(x);
    new_node ->next = prev->next;
    prev ->next =new_node;
}

void print(Node * head_ref){
    while(head_ref != NULL){
        cout<<head_ref->data<<" ";
        head_ref=head_ref->next;
    }
}

int main(){
    Node * head = NULL;
    insertHead(&head,5);
    insertHead(&head,7);
    insertTail(&head,9);
    insertGivenPosition(head->next,2);
    print(head);
}