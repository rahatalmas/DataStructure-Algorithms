#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};
Node *head = NULL;

void push_front(int data){
    Node *new_node = new Node();
    new_node->data=data;
    new_node->next = NULL;
    if(head == NULL){
         head = new_node;
         return;
    }
    Node * temp = head;
    new_node->next = temp;
    head = new_node;
}

void push_back(int data){
    Node *new_node = new Node();
    new_node->data=data;
    new_node->next = NULL;
    if(head == NULL){
         head = new_node;
         return;
    }
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(){
    Node * temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    //cout << &head << endl;
    push_back(5);
    push_back(6);
    push_front(4);
    printList();
}