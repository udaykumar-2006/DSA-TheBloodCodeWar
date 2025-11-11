#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int left =2 * i;
    int right = 2 * i + 1;

    if (left <= n && a[left] > a[largest])
        largest = left;
    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(a, n, i);
    }
}

void insert(int a[], int *n, int val) {
    (*n)++;
    a[*n] = val;
    int i = *n;
    while (i > 1 && a[i] > a[i / 2]) {
        swap(&a[i], &a[i / 2]);
        i = i / 2;
    }
}

int extractMax(int a[], int *n) {
    if (*n == 0) return -1;
    int max = a[1];
    a[1] = a[*n];
    (*n)--;
    heapify(a, *n, 1);
    return max;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[100];
    a[0] = 0;

    printf("Enter %d elements:\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    buildMaxHeap(a, n);

    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Extract Max\n3. Display Heap\n4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(a, &n, val);
        } else if (choice == 2) {
            int max = extractMax(a, &n);
            if (max == -1)
                printf("Heap is empty\n");
            else
                printf("Max element removed: %d\n", max);
        } else if (choice == 3) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        } else {
            break;
        }
    }

    return 0;
}
