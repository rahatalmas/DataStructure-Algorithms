#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(ll i=(a);i<(b);i++)

struct Node{
    int data;
    struct Node* next;
};

void insertHead(Node ** headref, int x){
    Node * temp = new Node();
    temp -> data = x;
    temp -> next = *headref;
    *headref = temp;   
}

void insertTail(Node ** headref,int x){
   Node * new_node = new Node();
   new_node->data=x;
   new_node->next=NULL;
   if(*headref == NULL){
       * headref = new_node;
       return;
   }
   Node * temp= *headref;
   while(temp->next != NULL){
       temp = temp ->next;
   }
   temp->next= new_node;
   return;
}

void insertNthPosition(Node ** headref,int x,int n){
    Node * new_node = new Node();
    new_node->data=x;
    if(n==1){
        new_node->next=*headref;
        *headref = new_node;
        return;
    }else{
        Node * temp = *headref;
        loop(i,0,n-2){
            temp = temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
}
/*
Node * deleteNode (Node * head,int x){

}
*/
void print(Node * headref){
    while(headref!=NULL){
        cout<<headref->data<<" ";
        headref=headref->next;
    }
    cout<<endl;
}
int main(){
    Node * head = NULL;
    insertHead(&head,1);
    insertTail(&head,6);
    insertTail(&head,5);
    insertHead(&head,2);
    insertNthPosition(&head,9,2);
    print(head);
}