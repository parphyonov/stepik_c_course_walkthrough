#include <stdio.h>

int divides(int a, int b) { return a % b == 0; }

void print_newline() { printf("\n"); }

void divisors(int n) {
    printf("%d: ", n);
    for (int i = 1; i <= n; i++) {
        if (divides(n, i)) printf("%d ", i);
    }
}

void all_divisors(int limit) {
    for (int i = 1; i <= limit; i++) {
        divisors(i);
        print_newline();
    }
}
int main() {
    all_divisors(100);
    return 0;
}