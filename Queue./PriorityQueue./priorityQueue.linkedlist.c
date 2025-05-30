#include <stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  int priority;
  struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
void enqueue(int data,int priority){
  struct Node *new=(struct Node*)malloc(sizeof(struct Node));
  if(new==NULL){
    printf("queue is empty");
  }
  new->data=data;
  new->priority=priority;
  new->next=NULL;
  if(front==NULL||priority<front->priority){
    new->next=front;
    front=new;
    
  }else{
    struct Node *temp=front;
    while(temp->next!=NULL&&temp->next->priority<=priority){
      temp=temp->next;
      
    }
    new->next=temp->next;
    temp->next=new;
  }
}
void dequeue(int priority){
  if(front==NULL){
    printf("queue is empty");
  }
  struct Node *temp=front;
 struct Node *prev=NULL;
 if(front->priority==priority){
   front=front->next;
   free(temp);
   return;
 }
 while(temp!=NULL && temp->priority!=priority){
   prev=temp;
   temp=temp->next;
 }
 
   
    prev->next=temp->next;
  free(temp);
}
void display(struct Node *head){
  if(head==NULL)return;
  printf("%d\n",head->data);
  display(head->next);
}
int main()
{
   enqueue(10,3);
   enqueue(20,2);
   enqueue(40,1);
   enqueue(50,6);
   display(front);
   dequeue(1);
   display(front);
}
