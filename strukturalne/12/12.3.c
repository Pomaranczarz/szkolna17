#include <stdio.h>
#include <string.h>

#define LINE_WIDTH 80
#define MAX_LEN 320
void PrintCentered(const char* str, unsigned length);

int main(void) {
    char str[MAX_LEN];
    printf("Podaj napis: ");
    fgets(str, MAX_LEN, stdin);
    PrintCentered(str, strlen(str) - 1);
    
    return 0;
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