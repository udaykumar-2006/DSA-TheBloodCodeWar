#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int top;
} DynStack;

void initStack(DynStack *s) {
    s->capacity = 2;
    s->top = -1;
    s->arr = (int *)malloc(s->capacity * sizeof(int));
}

void resize(DynStack *s) {
    s->capacity *= 2;
    s->arr = (int *)realloc(s->arr, s->capacity * sizeof(int));
}

void push(DynStack *s, int val) {
    if (s->top == s->capacity - 1) {
        resize(s);
    }
    s->arr[++s->top] = val;
    printf("Pushed %d\n", val);
}

int pop(DynStack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = s->arr[s->top--];
    printf("Popped %d\n", val);
    return val;
}

int peek(DynStack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top];
}

void freeStack(DynStack *s) {
    free(s->arr);
}

int main() {
    DynStack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);  

    printf("Top element: %d\n", peek(&s));

    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);  

    freeStack(&s);
    return 0;
}
