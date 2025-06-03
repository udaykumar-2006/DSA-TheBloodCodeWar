#include <stdio.h>
#define MAX 100
 int stack[MAX];
  int top=-1;
 
  int push(int data){
    if(top==MAX){
      printf("stack is overflow\n");
    }
  stack[++top]=data;
}
void pop(){
  if(top==-1){
    printf("stack is underflow\n");
  }
 
  printf("popped %d\n",stack[top--]);
}
void display(){
  for(int i=0;i<=top;i++){
    printf("%d\n",stack[i]);
  }
  
}
int main()
{
 
  push(1);
  push(2);
  push(3);
  push(4);
  display();
  pop();
  display();
}
