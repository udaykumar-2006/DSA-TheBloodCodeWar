#include <stdio.h>

void treeRec(int n) {
    if (n == 0) return;
    printf("%d ", n);
    treeRec(n - 1);   // Firstrecursive call
    treeRec(n - 1);   // Secondrecursive call
}

int main() {
    treeRec(3);
    return 0;
}
