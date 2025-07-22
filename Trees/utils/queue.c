#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* rchild;
    struct Node* lchild;
};


struct queue {
    int size;
    int front;
    int rear;
    struct Node** Q;  
};


void createQueue(struct queue* q, int size) {
    q->size = size;
    q->front = q->rear = 0;  
    q->Q = (struct Node**)malloc(sizeof(struct Node*) * q->size); 
}


void enqueue(struct queue* q, struct Node* x) {
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}


struct Node* dequeue(struct queue* q) {  
    struct Node* x = NULL;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct queue q) {  
    return q.front == q.rear;
}
