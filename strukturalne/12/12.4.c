#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_WIDTH 80
#define MAX_LEN 320

void PrintLeftAligned(char* str);
void PrintRightAligned(char* str);

int main(void) {
    char str[MAX_LEN];

    printf("Podaj napis: ");
    char c = getchar();
    int i = 0;
    while (c != EOF) {
        str[i++] = c;
        c = getchar();
    }
    str[i] = '\0';

    PrintLeftAligned(str);
    printf("\n");
    PrintRightAligned(str);

    return 0;
}

char* TrimLeft(char* str) {
    while (isspace(*str)) 
        str++;

    return str;
}

void PrintLeftAligned(char* str) {
    printf("%s", TrimLeft(str)); // :)
}

void PrintRightAligned(char* str) {
    int lines = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '\n')
            lines++;
    }

    char** str_array = (char**)malloc(sizeof(char*) * lines);
    for (int i = 0; i < lines; i++) 
        str_array[i] = (char*)calloc(LINE_WIDTH, sizeof(char));

    int inner_idx = 0;
    int str_array_idx = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '\n' || str[i] == '\0') {
            str_array_idx++;
            inner_idx = 0;
            continue;
        }
        
        str_array[str_array_idx][inner_idx] = str[i];
        inner_idx++;
    }

    for (int i = 0; i < lines; i++)
        printf("%*s\n", LINE_WIDTH, str_array[i]);

    for (int i = 0; i < lines; i++)
        free(str_array[i]);

    free(str_array);
}