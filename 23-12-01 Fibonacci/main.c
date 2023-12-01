#include <stdio.h>

void array_fib(int* array, const int* limit) {
    if (limit - array > 0) {
        int* p = array;
        *p = 1;
        if (limit - array >= 2) *(p + 1) = 1;
        if (limit - array >= 3) {
            for (p = array + 2; p < limit; p++) {
                *p = *(p - 2) + *(p - 1);
            }
        }
    }
}

void array_print(int* array, const int* limit) {
    for (int* p = array; p < limit; p++) printf("%d ", *p);
}

int main(void) {
    int array[] = {};
    array_fib(array, array);
    array_print(array, array);
    return 0;
}