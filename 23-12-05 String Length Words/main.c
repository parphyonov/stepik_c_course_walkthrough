#include <stdio.h>

int string_count(const char* str) {
    int pos = 0;
    if (str[0] != '\0') {
        while (str[pos] != '\0') pos++;
    }
    return pos;
}

int string_words(const char* str) {
    int words = 0;
    if (str[0] != '\0') {
        int pos = 0;
        while (pos <= string_count(str)) {
            if (str[pos] > 32) {
                if (str[pos + 1] <= 32) words++;
            }
            pos++;
        }
    }
    return words;
}

int main(void) {
    const char* mystr = "hello  world";
    printf("Length >>> %d;\n", string_count(mystr));
    printf("Words >>> %d;\n", string_words(mystr));
    return 0;
}