#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

void AppendToStringAndEnsureLength(char* str, unsigned* str_len, unsigned* current_capacity, char to_append);
unsigned Concatenate(char** result, unsigned num_of_args, ...);

int main(void) {
    char* result = NULL;
    Concatenate(&result, 4, "Siema", "to", "ja", "Guadelupe");
    printf("%s", result);

    free(result);

    return 0;
}

unsigned GetLen(const char* str) {
    unsigned len = 0;
    for (; *str != '\0'; str++, len++);

    return len;
}

void AppendToStringAndEnsureLength(char* str, unsigned* str_len, unsigned* current_capacity, char to_append) {
    if (*str_len + 1 >= *current_capacity) {
        *current_capacity = *current_capacity * 2;
        str = realloc(str, *current_capacity);
    }

    str[(*str_len)++] = to_append;
}

unsigned Concatenate(char** result, unsigned num_of_args, ...) {
    if (*result != NULL)
        free(*result);

    *result = (char*)malloc(20 * sizeof(char));
    unsigned resultCapacity = 20;
    unsigned resultLen = 0;

    va_list args;
    va_start(args, num_of_args);

    for (int i = 0; i < num_of_args; i++) {
        const char* current_str = va_arg(args, const char*);
        for (int current_str_index = 0; current_str_index < strlen(current_str); current_str_index++)
            AppendToStringAndEnsureLength(*result, &resultLen, &resultCapacity, current_str[current_str_index]);

        AppendToStringAndEnsureLength(*result, &resultLen, &resultCapacity, ' ');
    }

    return resultLen;
}