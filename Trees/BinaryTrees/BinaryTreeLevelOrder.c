#include <stdio.h>
#include <stdlib.h>
#include "../utils/queue.h"
#include "../utils/node.h"



struct Node *root = NULL;

void TreeCreate() {
    struct Node *p, *t;
    int x;
    struct queue q;
    createQueue(&q, 100); 

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);  

    while (!isEmpty(q)) {
        p = dequeue(&q);

        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void LevelOrder(struct Node *root) {
    struct queue q;
    createQueue(&q, 100);  

    if (root == NULL) return;

    enqueue(&q, root);

    while (!isEmpty(q)) {
        struct Node *p = dequeue(&q);
        printf("%d ", p->data);

        if (p->lchild != NULL)
            enqueue(&q, p->lchild);
        if (p->rchild != NULL)
            enqueue(&q, p->rchild);
    }
}

int main(){
  TreeCreate();

    printf("\nLevel Order BFS traversal:\n");
    LevelOrder(root);

    return 0;
  
}
