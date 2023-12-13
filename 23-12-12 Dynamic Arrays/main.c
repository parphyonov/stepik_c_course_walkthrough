#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void intptr_print(const int64_t* x) {
    if (x == NULL)
        printf("None");
    else
        printf("%" PRId64, *x);
}

int64_t* array_int_min(int64_t* array, size_t size) {
    if (array != NULL) {
        int64_t* min = &array[0];
        for (size_t i = 0; i < size; i++)
            if (array[i] < *min) min = &array[i];
        return min;
    } else
        return NULL;
}

void array_int_fill(int64_t* array, size_t size) {
    for (size_t i = 0; i < size; i++) scanf("%" SCNd64, &array[i]);
}

int64_t* array_int_read(size_t* size) {
    scanf("%zu", size);
    int64_t* array = malloc(*size * sizeof(int64_t));
    if (array) array_int_fill(array, *size);
    return array;
}

int main(void) {
    size_t size = 0;
    int64_t* array = array_int_read(&size);
    const int64_t* min = array_int_min(array, size);
    intptr_print(min);
    free(array);
    return 0;
}