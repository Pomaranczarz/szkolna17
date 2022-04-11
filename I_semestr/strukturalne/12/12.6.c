#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINE_WIDTH 80
#define MAX_LEN 320
void PrintCentered(const char* str, unsigned length);
void StrToUpper(char* str);

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

    printf("Podano: \n%s", str);

    printf("Po zmianie: \n");
    StrToUpper(str);
    PrintCentered(str, i);

    return 0;
}

void StrToUpper(char* str) {
    while (*str != '\0') {
        if (isalpha(*str))
            *str = toupper(*str);

        str++;
    }
}

void PrintCentered(const char* str, unsigned length) {
    char* str_array[length / LINE_WIDTH + 1];
    int i = 0;
    int j = 0;
    while (i < length) {
        str_array[j] = str + i;
        i += LINE_WIDTH;
        j++;
    }

    for (int k = 0; k < j; k++) {
        int spaces = (LINE_WIDTH - strlen(str_array[k])) / 2;
        for (int l = 0; l < spaces; l++) {
            printf(" ");
        }
        printf("%s\n", str_array[k]);
    }

}