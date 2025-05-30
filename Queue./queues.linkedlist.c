#include <stdio.h>
#include<stdlib.h>
struct Node{
  int data;
 struct Node*next;
}*front=NULL,*rear=NULL;

void enqueue(int data){
 struct Node*new;
 new=(struct Node*)malloc(sizeof(struct Node));
 if(new==NULL){
   printf("queue is full");
 }else{
   new->data=data;
   new->next=NULL;
   if(front==NULL){
     front=rear=new;
     
   }else{
     rear->next=new;
     rear=new;
   }
 }
  
}
int dequeue(){
  int x=-1;
  struct Node *new;
  if(front==NULL){
    printf("queue is empty");
    
  }else{
    x=front->data;
    new=front;
    front=front->next;
    free(new);
  }
  return x;
}

void display(struct Node *head){
  if(head==NULL){
    return;
  }else{
    printf("%d\n",head->data);
    display(head->next);
  }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(front);
}
