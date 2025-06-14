void headRec(int n) {
    if(n == 0) return;
    headRec(n - 1);
    printf("%d ", n);
}
