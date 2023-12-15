#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void array_int_print(const int64_t* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%" PRId64 " ", array[i]);
    }
}

void print_newline(void) { printf("\n"); }

size_t read_size(void) {
    size_t output;
    scanf("%zu", &output);
    return output;
}

void array_int_fill(int64_t* array, size_t size) {
    for (size_t i = 0; i < size; i++) scanf("%" SCNd64, &array[i]);
}

int64_t* array_int_read(size_t* size) {
    *size = read_size();
    int64_t* array = malloc(*size * sizeof(int64_t));
    if (array) {
        array_int_fill(array, *size);
    }
    return array;
}

int64_t** marray_read(size_t* rows, size_t** sizes) {
    *rows = read_size();
    *sizes = malloc(*rows * sizeof(size_t));
    int64_t** marray = malloc(*rows * sizeof(int64_t*));

    for (size_t r = 0; r < *rows; r++) {
        marray[r] = array_int_read(&(*sizes)[r]);
    }

    return marray;
}

void marray_print(int64_t** marray, const size_t* sizes, size_t rows) {
    for (size_t i = 0; i < rows; i = i + 1) {
        array_int_print(marray[i], sizes[i]);
        print_newline();
    }
}

void marray_free(int64_t** marray, size_t rows) {
    for (size_t r = 0; r < rows; r++) free(marray[r]);
    free(marray);
}

int64_t* int64_ptr_min(int64_t* x, int64_t* y) {
    int64_t* out = NULL;
    if (x != NULL && y != NULL) {
        if (*x > *y) out = y;
        else out = x;
    } else if (x == NULL) out = y;
    else if (y == NULL) out = x;
    return out;
}

int64_t* marray_int_min(int64_t** marray, size_t* sizes, size_t rows) {
    int64_t* min = NULL;
    for (size_t r = 0; r < rows; r++)
        for (size_t c = 0; c < sizes[r]; c++)
            min = int64_ptr_min(min, &marray[r][c]);
    return min;
}

void marray_normalize( int64_t** marray, size_t* sizes, size_t rows, int64_t m ) {
    for (size_t r = 0; r < rows; r++)
        for (size_t c = 0; c < sizes[r]; c++)
            marray[r][c] -= m;
}

// Test Sequence
// 3 3 1 2 3 3 4 5 6 3 7 8 -9
int main(void) {
    // inits
    size_t rows = 0;
    size_t* sizes = NULL;
    int64_t** marray = marray_read(&rows, &sizes);
    // finding min
    int64_t* min = marray_int_min(marray, sizes, rows);
    // normalize
    if (min != NULL) {
        marray_normalize(marray, sizes, rows, *min);
    }
    // output
    marray_print(marray, sizes, rows);
    // free
    free(sizes);
    marray_free(marray, rows);
    return 0;
}