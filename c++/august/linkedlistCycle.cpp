#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

class Node{
    private:
      int data;
      Node * next;
    public:
      Node(int data);
    friend class LinkedList;
};
Node::Node(int data){
    this->data = data;
    this->next = NULL;
}

class LinkedList{
    private:
      Node * head = NULL;
    public:  
      void push_back(int data);
      void push_front(int data);
      void createLoop(int pos); //or cycle
      int detectLoop();  //or cycle
      void printList();
};
void LinkedList::push_back(int data){
    Node * new_node = new Node(data);
    if(this->head == NULL){
        this->head = new_node;
        return;
    }
    Node * temp = this->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void LinkedList::push_front(int data){
    Node * new_node = new Node(data);
    if(this->head == NULL){
        this->head = new_node;
        return;
    }
    new_node->next = head;
    this->head = new_node;
    return;
}

int LinkedList::detectLoop(){
    Node * fastptr = this->head;
    Node * slowptr = this->head;
    while(slowptr!=NULL and fastptr!=NULL and fastptr->next!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr == fastptr){
            return 1;
        }
    }
    return 0;
}

void LinkedList::createLoop(int pos){
    Node * temp = this->head;
    Node * tail = this->head;
    while(pos--){
        temp = temp->next;
    }
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = temp;
    return;
}

void LinkedList::printList(){
    Node * temp = this->head;
    while(temp->next!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << temp->data << endl;
}

int main(){
    LinkedList l;
    for(int i=0;i<10;i++){
        l.push_back(i);
    }
    l.printList();
    l.createLoop(3);
    //l.printList(); need to update printing function for the loop...
    cout << l.detectLoop() << endl;
}