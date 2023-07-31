#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * createNode(int x){
    Node * new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void insertHead(Node ** head_ref,int x){
    Node * new_node = createNode(x);
    new_node -> data = x;
    new_node -> next = *head_ref;
    *head_ref = new_node;
}

void deleteByKey(Node ** head_ref,int key){
    Node * temp = *head_ref;
    if(temp == NULL){
        return;
    }
    if(temp->data == key){
        *head_ref=temp->next;
        delete(temp);
        return;
    }
    Node * prev;
    while(temp -> data != key){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete(temp);
}

void deleteGivenPosition(){
    
}

void deleteLinkedList(Node ** head_ref){
    Node * current = *head_ref;
    Node * nextNode = NULL;
    while(current != NULL){
        nextNode = current->next;
        delete(current);
        current = nextNode;
    }
    *head_ref = NULL;
}

void print(Node * head_ref){
    while(head_ref != NULL){
        cout<<head_ref->data<<" ";
        head_ref=head_ref->next;
    }
    cout<<endl;
}

int main(){
    Node * head = NULL;
    insertHead(&head,5);
    insertHead(&head,6);
    print(head);
    deleteByKey(&head,6);
    print(head);
    deleteLinkedList(&head);
    print(head);

}