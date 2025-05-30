#include <stdio.h>
struct Node {
  int data;
  struct Node *next;
  
};
struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int data){
  struct Node *new=(struct Node*)malloc(sizeof(struct Node));
  if(new==NULL){
    printf("queue is empty");
  }
  new->data=data;
    new->next=NULL;
  if(front==NULL){
    front=rear=new;
    rear->next=front;
  }else{
   rear->next=new;
   rear=new;
    rear->next=front;
  }
}
void dequeue(){
  struct Node *temp=front;
  if(front==rear){
    printf("queue is empty");
  }
  else{
    front=front->next;
    rear->next=front;
    free(temp);
  }
}
void display(){
  if(front == NULL){
    printf("Queue is empty\n");
    return;
  }
  
  struct Node *temp = front;
  printf("Queue elements: ");
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while(temp != front);
  printf("\n");
}

int main()
{
     enqueue(10);
  enqueue(20);
  enqueue(30);
  display();
  dequeue();
  display();
  enqueue(40);
  display();
  
  return 0;
}
