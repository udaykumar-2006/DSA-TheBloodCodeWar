#include <stdio.h>
#include<stdlib.h>
//there are 2 types of dequeue those are i/p restricted dequeue and o/p restricted dequeue
struct Node{
  int data;
 struct Node*prev;
 struct Node*next;
}*front=NULL,*rear=NULL;

void denqueueFront(int data){
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  if(newNode==NULL){
    printf("dequeue if full");
    return;
  }
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=front;
    if(front==NULL){
      rear=front=newNode;
    }else{
      front->prev=newNode;
      front=newNode;
    }
  
}
void denqueueRear(int data){
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  if(!newNode){
    printf("dequeue if full");
    return;
  }
  newNode->data=data;
  newNode->prev=rear;
  newNode->next=NULL;

if(rear==NULL){
  rear=front=newNode;
}else{
  rear->next=newNode;
  rear=newNode;
}
}
void dequeueFront(){
  
  if(front==NULL){
    printf("it is empty");
    return;
  }
  
  struct Node *temp=front;
  front=front->next;
  if(front!=NULL){
    front->prev=NULL;
  }else{
    rear=NULL;
  }
  free(temp);
  
}
void dequeueRear(){
  if(rear==NULL){
    printf("qeueue is empty");
    return;
  }
  struct Node *temp=rear;
  rear=rear->prev;
  
  if(rear!=NULL){
    rear->next=NULL;
  }else{
    front=NULL;
    
  }
  free(temp);
  
}
void display(struct Node*head){
  if(head==NULL){
    return;
  }else{
    printf("%d\n",head->data);
    display(head->next);
  }
}
int main()
{
 denqueueRear(10);
 denqueueFront(20);
 denqueueFront(30);
 denqueueRear(40);
  display(front);
   
}
