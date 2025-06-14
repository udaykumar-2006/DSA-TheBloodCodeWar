void tailRec(int n) {
    if(n == 0) return;
    printf("%d ", n);
    tailRec(n - 1);
}
