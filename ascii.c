#include <stdio.h>

int main() {
    char inputChar;
    printf("Podaj dowolny znak z tabeli ASCII:\n");
    inputChar = getchar();
    printf("Podales %c [%i]\nNastepny znak: %c\n", inputChar, inputChar, inputChar + 1);
    if (inputChar >= 'a' && inputChar <= 'z') {
        printf("Wpisales mala litere. Jej duza wersja: %c\n", inputChar + 'A' - 'a');
    }

    return 0;
}