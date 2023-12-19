#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct array_int {
    int64_t* data;
    size_t size;
};

struct maybe_int64 {
    int64_t value;
    bool valid;
};

struct maybe_int64 some_int64(int64_t i) { return (struct maybe_int64){i, true}; }

const struct maybe_int64 none_int64 = {0};

size_t read_size() {
    size_t sz = 0;
    scanf("%zu", &sz);
    return sz;
}

int64_t read_int64(void) {
    int64_t out = 0;
    scanf("%" SCNd64, &out);
    return out;
}

void array_int_fill(int64_t* array, size_t sz) {
    for (size_t i = 0; i < sz; i = i + 1) {
        array[i] = read_int64();
    }
}

struct array_int array_int_read() {
    const size_t size = read_size();
    if (size > 0) {
        int64_t* array = malloc(sizeof(int64_t) * size);
        array_int_fill(array, size);
        return (struct array_int){.data = array, .size = size};
    } else
        return (struct array_int){0};
}

// возвращает ошибку если индекс за пределами массива
struct maybe_int64 array_int_get(struct array_int a, size_t i) {
    if (i < 0 || i >= a.size) return (struct maybe_int64){.valid = false};
    return (struct maybe_int64){.value = a.data[i], .valid = true};
}

// возвращает false если индекс за пределами массива
bool array_int_set(struct array_int a, size_t i, int64_t value) {
    if (array_int_get(a, i).valid) {
        a.data[i] = value;
        return true;
    }
    return false;
}

void array_int_print(struct array_int array) {
    for (size_t i = 0; i < array.size; i = i + 1) {
        printf("%" PRId64 " ", array_int_get(array, i).value);
    }
}

struct maybe_int64 array_int_min(struct array_int array) {
    struct maybe_int64 min;
    if (array.size > 0) {
        min.value = array.data[array.size - array.size];
        for (size_t i = 1; i < array.size; i++) {
            if (array.data[i] < min.value) min = (struct maybe_int64){.value = array.data[i], .valid = true};
        }
    } else {
        min = (struct maybe_int64){.valid = false};
    }
    return min;
}

void array_int_free(struct array_int a) {
    if (a.size > 0) {
        free(a.data);
        a.size = 0;
    }
}

int main(void) {
    struct array_int a = array_int_read();
    struct maybe_int64 min = array_int_min(a);
    if (min.valid) {
        printf("MIN >>> %" PRId64 "\n", min.value);
    }
    array_int_free(a);
    return 0;
}