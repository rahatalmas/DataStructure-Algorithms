#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void push(struct Node ** headref,int x){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node -> data = x;
    new_node ->next = *headref;
    *headref = new_node;
}

void pushAfterGivenNode(struct Node * prev,int y){
   struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
   if(prev == NULL){
       printf("previous cant be NULL\n");
       return;
   }
   new_node->data = y;
   new_node->next = prev->next;
   prev->next = new_node;
}

void append(struct Node ** headref,int z){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node ->data = z;
    new_node ->next = NULL;
    struct Node * last = *headref;
    if(last -> next == NULL){
        *headref = new_node;
        return;
    }
    while(last -> next != NULL){
        last = last -> next;
    }
    last -> next = new_node;
    return;
}

void print(struct Node * head){
   while(head != NULL){
       printf("%d ",head->data);
       head = head->next;
   }
}

int main(){
    struct Node * head = NULL;
    push(&head,1);
    push(&head,1);
    push(&head,1);
    pushAfterGivenNode(head->next,5);
    append(&head,3);
    print(head);
}