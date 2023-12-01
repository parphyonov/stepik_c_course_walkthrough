#include <stdio.h>

int is_prime(int num) {
    if (num < 2) return 0;
    int i = 2;
    while (num % i != 0) i++;
    return i == num;
}

void factorize(int n, int* a, int* b) {
    if (n == 1 || is_prime(n)) {
        *a = 1;
        *b = n;
    } else {
        if (n == 0) {
            *a = 0;
            *b = 0;
        } else {
            for (int i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    if (i <= n / i) {
                        *a = i;
                        *b = n / i;
                        break;
                    }
                }
            }
        }
    }
}

int main(void) {
    int a, b;
    factorize(22, &a, &b);
    printf("| A >>> %d | B >>> %d |\n", a, b);
    return 0;
}