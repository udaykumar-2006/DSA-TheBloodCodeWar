#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"


struct queue {
    int size;
    int front;
    int rear;
    struct Node** Q;
};

void createQueue(struct queue* q, int size);
void enqueue(struct queue* q, struct Node* x);
struct Node* dequeue(struct queue* q);
int isEmpty(struct queue q);

#endif
