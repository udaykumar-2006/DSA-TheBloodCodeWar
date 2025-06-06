#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}


void enqueue(struct queue*q,int x){
  if((q->rear+1)%q->size==q->front){
    printf("queue is full");
  }else{
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
  }
}


int dequeue(struct queue *q){
  int x=-1;
  if(q->front==q->rear){
    printf("queue is empty");
  }else{
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
  }
  return x;
}


void display(struct queue *q) {
    int i = (q->front + 1) % q->size;

    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    while (i != (q->rear + 1) % q->size) {
        printf("%d\n", q->Q[i]);
        i = (i + 1) % q->size;
    }
}


int main() {
    struct queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}
