#include <stdio.h>

void funB(int n); // Forward declaration

void funA(int n) {
    if (n <= 0)
        return;
    printf("A: %d\n", n);
    funB(n - 1);
}

void funB(int n) {
    if (n <= 0)
        return;
    printf("B: %d\n", n);
    funA(n / 2); 
}

int main() {
    funA(20);
    return 0;
}
