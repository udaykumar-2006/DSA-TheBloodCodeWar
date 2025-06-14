#include <stdio.h>

int nestedRec(int n) {
    if (n > 100)
        return n - 10;
    return nestedRec(nestedRec(n + 11)); // Recursion in recursion
}

int main() {
    int res = nestedRec(95);
    printf("Result: %d\n", res);
    return 0;
}
