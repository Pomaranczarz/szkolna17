#include <stdio.h>

void printPattern(char c, unsigned len) {
    while (len--) {
        printf("%c", c);
    }
}

int main() {
    char c;
    unsigned len;

    printf("Podaj znak i dlugosc ciagu: \n");
    scanf("%c %u", &c, &len);

    printf("\n");
    printPattern(c, len);
}