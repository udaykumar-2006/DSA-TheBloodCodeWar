#include <stdio.h>
#include<stdlib.h>
struct Node{
  struct Node*Lchild;
  struct Node*Rchild;
  int data;
}*root=NULL;
//binary search tree
int Rsearch(struct Node*head,int target){
  if(head==NULL){
    printf("target is not found\n");
    
  }else if(target==head->data){
    return head->data;
  }else if(target<head->data){
    return Rsearch(head->Lchild,target);
  }else{
    return Rsearch(head->Rchild,target);
  }
}
int search(struct Node*head,int target){
  
  while(head){
    if(target==head->data){
      return head->data;
    }else if(target<head->data){
      head=head->Lchild;
    }else{
      head=head->Rchild;
    }
    
  }return 0;
}
//Normal Insert function
void insert(struct Node** head, int data) {
  struct Node* tail = NULL;
  struct Node* current = *head;
  while (current) {
    tail = current;
    if (data == current->data) {
      printf("cannot insert duplicate in bst\n");
      return;
    } else if (data < current->data) {
      current = current->Lchild;
    } else {
      current = current->Rchild;
    }
  }
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->Lchild = newNode->Rchild = NULL;

  if (tail == NULL) {
    *head = newNode;  // first insertion
  } else if (data < tail->data) {
    tail->Lchild = newNode;
  } else {
    tail->Rchild = newNode;
  }
}

//recursive Insert function
struct Node* Rinsert(struct Node*head,int data){
 
  if(head==NULL){
     struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
     temp->data=data;
     temp->Lchild=temp->Rchild=NULL;
     return temp;
  }
  if(data<head->data){
    head->Lchild=Rinsert(head->Lchild,data);
  }
  else{
    head->Rchild=Rinsert(head->Rchild,data);
  }
  return head;
}
void InOrder(struct Node*head){
  if(head==NULL){
    return;
  }else{
    InOrder(head->Lchild);
    printf("%d\n",head->data);
    InOrder(head->Rchild);
  }
  
}
int height(struct Node*head){
  if(head==NULL){
    return 0;
  }
  int x=height(head->Lchild);
  int y=height(head->Rchild);
  return x>y?x+1:y+1;
}
struct Node*InPre(struct Node*head){
  while(head &&head->Rchild!=NULL){
    head=head->Rchild;
  }
  return head;
}
struct Node*InSuc(struct Node*head){
  while(head &&head->Lchild!=NULL){
    head=head->Lchild;
  }
  return head;
}

struct Node* Rdelete(struct Node* head, int key) {
    struct Node* q;
    if (head == NULL) {
        return NULL;
    }
    if (key < head->data) {
        head->Lchild = Rdelete(head->Lchild, key);
    } else if (key > head->data) {
        head->Rchild = Rdelete(head->Rchild, key);
    } else {
       
        if (head->Lchild == NULL && head->Rchild == NULL) {
            free(head);
            return NULL;
        }
        if (height(head->Lchild) > height(head->Rchild)) {
            q = InPre(head->Lchild);
            head->data = q->data;
            head->Lchild = Rdelete(head->Lchild, q->data);
        } else {
            q = InSuc(head->Rchild);
            head->data = q->data;
            head->Rchild = Rdelete(head->Rchild, q->data);
        }
    }
    return head;
}


int main()
{
    root = Rinsert(root, 10);
    root = Rinsert(root, 20);
    root = Rinsert(root, 30);
    insert(&root, 5);  

    printf("Before deletion:\n");
    InOrder(root); 

    root = Rdelete(root, 5); // 

    printf("After deletion:\n");
    InOrder(root); 
}
