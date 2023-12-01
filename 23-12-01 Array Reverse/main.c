#include <stdio.h>

void array_reverse(int* array, int size) {
    for (int i = 0; i < size / 2; i++) {
        int* a = &array[i];
        int* b = &array[size - 1 - i];
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void array_reverse_ptr(int* array, const int* limit) {
    long int halfsize = (limit - array) / 2;
    for (int* p = array; p < array + halfsize; p++) {
        int tmp = *p;
        *p = *(limit - 1);
        *(limit - 1) = tmp;
        limit--;
    }
}

void array_print(int* array, const int* limit) {
    for (int* p = array; p < limit; p++) printf("%d ", *p);
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5, 6};
    array_reverse(array, 6);
    array_print(array, array + 6);
    printf("\n");
    array_reverse_ptr(array, array + 6);
    array_print(array, array + 6);
    return 0;
}