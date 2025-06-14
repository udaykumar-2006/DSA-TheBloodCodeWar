#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int s, int e) {
    int i = s - 1;
    int j = e + 1;
    int pivot = a[s];

    while (1) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        swap(&a[i], &a[j]);
    }
}

void QuickSort(int a[], int l, int h) {
    if (l < h) {
        int j = partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j + 1, h);
    }
}


int main() {
    int a[] = { 24, 9, 29, 14, 19, 27 };
    int n = sizeof(a) / sizeof(a[0]);

    QuickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
