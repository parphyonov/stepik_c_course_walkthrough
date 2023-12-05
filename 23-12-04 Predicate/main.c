#include <stdio.h>

int predicate(int num) { return num % 3 == 0; }

int array_contains(int* array, const int* limit, int** position) {
    int out = 0;
    *position = array;
    for (int* p = array; p < limit; p++) {
        if (predicate(*p)) {
            **position = *p;
            out = 1;
            break;
        }
    }
    return out;
}

int main(void) {
    int array[] = {2, 4, 16, 15};
    int* position = NULL;
    if (array_contains(array, array + 4, &position))
        printf("Success [%d]", *position);
    else
        printf("Fail [%d]", *position);
    return 0;
}