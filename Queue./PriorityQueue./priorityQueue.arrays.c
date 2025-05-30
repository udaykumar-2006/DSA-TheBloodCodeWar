#include <stdio.h>

//priority queues using arrays 

#define MAX 100

int data[MAX],priority[MAX],size=0;

void enqueue(int d,int p){
  if(size==MAX)return;
  data[size]=d;
  priority[size]=p;
  size++;
}

void dequeue(int p){
  if(size==0) return;
 int index=-1;
 for(int i=0;i<size;i++){
   if(priority[i]==p) index=i;
   break;
 }
 int toBedeleted=index;
 for(int i=index;i<size-1;i++){
    data[i]=data[i+1];
    priority[i]=priority[i+1];
 
}
size--;
}
void display(){
  for(int i=0;i<size;i++){
    printf("%d\n",data[i]);
  }
}
int main()
{
    enqueue(20,1);
    enqueue(30,3);
    enqueue(40,2);
    enqueue(10,4);
    dequeue(1);
    display();
}
