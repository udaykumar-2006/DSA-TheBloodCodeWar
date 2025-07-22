#include <stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node*prev;
  struct Node*next;
};
struct Node*createNode(int data){
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  if(newNode==NULL){
    printf("allocation failed\n");
    return NULL;
  }
  newNode->data=data;
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
  
}
void insertAtbeginning(struct Node**head,int data){
  struct Node*newNode=createNode(data);
  newNode->next=*head;
  
  if(*head!=NULL){
    (*head)->prev=newNode;
    
  }
  *head=newNode;
}
void insertAtEnd(struct Node**head,int data){
  struct Node*newNode=createNode(data);
  if(*head==NULL){
    *head=newNode;
    return;
  }
  struct Node*temp=*head;
  while(temp->next!=NULL){
    temp=temp->next;
    
  }
  temp->next=newNode;
  newNode->prev=temp;
}
void insertAtPosition(struct Node**head,int data,int pos){
  struct Node*newNode=createNode(data);
  if(newNode==NULL)return;
  
  if(pos==1){
  newNode->next=*head;
  *head=newNode;
  return;
  }
  struct Node*temp=*head;
  for(int i=1;i<pos-1&&temp!=NULL;i++){
    temp=temp->next;
  }
  if(temp==NULL){
    printf("invalid position\n");
    free(newNode);
    return;
    
  }
  newNode->next=temp->next;
  newNode->prev=temp;
  
  if(temp->next!=NULL){
    temp->next->prev=newNode;
  }
  temp->next=newNode;
  
  
}
void deleteAtPosition(struct Node**head,int pos){
  if(*head==NULL){
    printf("List is empty\n");
    return;
  }
  struct Node*temp=*head;
  if(pos==1){
    *head=temp->next;
    if(*head!=NULL){
      (*head)->prev=NULL;
    }
     free(temp);
  return;
  }
  for(int i=1;i<pos&&temp!=NULL;i++){
    temp=temp->next;
  }
  if(temp==NULL){
    printf("invalid position\n");
    return;
  }
  if(temp->prev!=NULL){
    temp->prev->next=temp->next;
  }
  if(temp->next!=NULL){
    temp->next->prev=temp->prev;
  }
  free(temp);
 
  
}
void display(struct Node* head) {
    printf("DLL: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
   struct Node* head = NULL;

    insertAtbeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);
    display(head);  
    deleteAtPosition(&head, 2);
    display(head);  

    deleteAtPosition(&head, 1);
    display(head);  

    deleteAtPosition(&head, 1);
    display(head);  
    return 0;
}
