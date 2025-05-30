#include <stdio.h>
#include<stdlib.h>
//queue using 2 stacks 
#define MAX 100
int stack1[MAX],stack2[MAX];
int top1=-1;
int top2=-1;
void push1(int x) {stack1[++top1]=x;}
void push2(int x) {stack2[++top2]=x;}
int pop1() {return stack1[top1--];}
int pop2() {return stack2[top2--];}
int isEmpty1() {return top1==-1;}
int isEmpty2() {return top2==-1;}

void enqueue(int data){
  push1(data);
  printf("element is enqueued");
  
}
int dequeue(){
  if(isEmpty1()&&isEmpty2()){
    printf("queue is empty");
    return -1;
  }
  
  if(isEmpty2()){
    while(!isEmpty1()){
      push2(pop1());
    
    }
  }
  return pop2();
}
void displayQueue() {
    printf("Queue elements (Front to Rear): ");

    
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

   
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }

    printf("\n");
}


int main()
{
   enqueue(10);
enqueue(20);
enqueue(30);
dequeue();     
enqueue(40);
displayQueue();
}
