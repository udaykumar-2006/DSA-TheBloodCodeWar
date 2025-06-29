#include <stdio.h>
#include<stdlib.h>

struct Node{
  struct Node*Lchild;
  struct Node*Rchild;
  int data;
  int height;
}*root=NULL;
int NodeHeight(struct Node*head){
  int hL,hR;
  hL=head && head->Lchild?head->Lchild->height:0;
  hR=head && head->Rchild?head->Rchild->height:0;

 return hL>hR?hL+1:hR+1;
}
int Balancefactor(struct Node*head){
  int hL,hR;
  hL=head && head->Lchild?head->Lchild->height:0;
  hR=head && head->Rchild?head->Rchild->height:0;
  return hL-hR;
  
}
struct Node*LLRotation(struct Node*head){
  struct Node*headL=head->Lchild;
  struct Node*headLR=headL->Rchild;
  headL->Rchild=head;
  head->Lchild=headLR;
  head->height=NodeHeight(head);
  headL->height=NodeHeight(headL);
  
  if(root==head){
    root=headL;
  }
  return headL;
}
struct Node*RRRotation(struct Node*head){
  struct Node*headR=head->Rchild;
  struct Node*headRL=headR->Lchild;
  headR->Lchild=head;
  head->Rchild=headRL;
  head->height=NodeHeight(head);
  headR->height=NodeHeight(head);
  
  if(root==head){
    root=headR;
  }
  return headR;
}
struct Node* LRRotation(struct Node* head) {
    head->Lchild = RRRotation(head->Lchild);
    return LLRotation(head);
}

struct Node* RLRotation(struct Node* head) {
    head->Rchild = LLRotation(head->Rchild);
    return RRRotation(head);
}
struct Node* Rinsert(struct Node*head,int data){
 
  if(head==NULL){
     struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
     temp->data=data;
     temp->height=1;
     temp->Lchild=temp->Rchild=NULL;
     return temp;
  }
  if(data<head->data){
    head->Lchild=Rinsert(head->Lchild,data);
  }
  else{
    head->Rchild=Rinsert(head->Rchild,data);
  }
  head->height=NodeHeight(head);
  
    if(Balancefactor(head)==2 && Balancefactor(head->Lchild)==1){
    return LLRotation(head);
    }else if(Balancefactor(head)==2 && Balancefactor(head->Lchild)==-1){
      return LRRotation(head);
    }else if(Balancefactor(head)==-2 && Balancefactor(head->Rchild)==-1){
      return RRRotation(head);
    }else if(Balancefactor(head)==-2 && Balancefactor(head->Rchild)==1){
      return RLRotation(head);
    }
  
  return head;
}


int main()
{
    root = Rinsert(root, 30);
    root = Rinsert(root, 20);
    root = Rinsert(root, 10); 

    root = Rinsert(root, 40);
    root = Rinsert(root, 50); 

    root = Rinsert(root, 25); 

    root = Rinsert(root, 45);
    root = Rinsert(root, 60); 

    printf("🌳\n");

    return 0;
}
