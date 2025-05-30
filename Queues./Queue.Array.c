
#include <stdio.h>
#include <stdlib.h>
//queue using arrays
//here the front and rear are not address pointers those are index pointer (dont confuse in it )
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

void enqueue(struct queue *q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q) {
    int x = -1;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d\n", q->Q[i]);
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
