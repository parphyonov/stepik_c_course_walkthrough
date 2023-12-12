#include <inttypes.h>
#include <stdio.h>

size_t count_zeroes(const void* data, size_t sz) {
    const char* bytePtr = (char*)data;
    size_t count = 0;
    for (size_t i = 0; i < sz; i++) {
        if (bytePtr[i] == 0) count++;
    }
    return count;
}

int main(void) {
    uint32_t array[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233};
    size_t bSize = sizeof(array);
    printf("%zu\n", count_zeroes(array, bSize));
    return 0;
}