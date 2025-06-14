#include <stdio.h>

void headRec(int n) {
    if (n == 0) return;
    headRec(n - 1);   
    printf("%d ", n); 
}

int main() {
    headRec(5);
    return 0;
}
