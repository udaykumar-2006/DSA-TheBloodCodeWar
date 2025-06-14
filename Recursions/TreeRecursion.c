void treeRec(int n) {
    if(n == 0) return;
    printf("%d ", n);
    treeRec(n - 1);
    treeRec(n - 1);
}
