#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 120
#define LINE_WIDTH 80

void ReverseC(char* begin, char* end);
void PrintCentered(const char* str, unsigned length);

int main(void) {
    char str[MAX_LEN] = { '\0' };
    fgets(str, MAX_LEN, stdin);

    ReverseC(str, str + strlen(str));
    PrintCentered(str, strlen(str));

    return 0;
}

void swapC(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void ReverseC(char* begin, char* end) {
    for (int i = 0, j = (end - begin) - 1; i < (end - begin) / 2; i++, j--)
        swapC(&begin[i], &begin[j]);
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

void StrToUpper(char* str) {
    while (*str != '\0') {
        if (isalpha(*str))
            *str = toupper(*str);

        str++;
    }
}