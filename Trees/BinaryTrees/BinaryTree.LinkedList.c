#include <stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node*left;
  struct Node*right;
};
struct Node*createNode(int data){
  struct Node*newRoot=(struct Node*)malloc(sizeof(struct Node));
  newRoot->data=data;
  newRoot->left=newRoot->right=NULL;
  return newRoot;
}
void preOrder(struct Node*root){
  if(root==NULL) return;
  printf("%d\n",root->data);
  preOrder(root->left);
  preOrder(root->right);
  
}
void inOrder(struct Node*root){
  if(root==NULL) return;
  inOrder(root->left);
  printf("%d\n",root->data);
  inOrder(root->right);
}
void postOrder(struct Node*root){
  if(root==NULL) return;
   postOrder(root->left);
   postOrder(root->right);
  printf("%d\n",root->data);
   
}
int main()
{
    struct Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    
    
    printf("This is preOrder traversal\n");
    preOrder(root);
    printf("This is inOrder traversal\n");
    inOrder(root);
    printf("This is postOrder traversal\n");
    postOrder(root);

    return 0;
}
