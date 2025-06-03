#include <stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
};
void push(struct Node**head,int data){
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->next=*head;
  *head=newNode;
  
}
void pop(struct Node**head){
  if(*head==NULL){
    printf("nothing to pop\n");
  }
  struct Node*temp=*head;
  (*head)=(*head)->next;
  free(temp);
}
void display(struct Node*head){
  if(!head){
    printf("nothing\n");
    
  }
  else{
    printf("%d\n",head->data);
    display(head->next);
  }
}
int main()
{   struct Node*head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    display(head);
    pop(&head);
    display(head);
}
