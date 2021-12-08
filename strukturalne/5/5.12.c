#include <stdio.h>

int main() {
    printf("Podaj znak: \n");
    char c = getchar();

    if (c == '$')
        printf("To znak dolara");
    else if (c >= 'a' && c <= 'z')
        printf("To mala litera alfabetu");
    else if (c >= 'A' && c <= 'Z')
        printf("To duza litera alfabetu");
    else if (c >= '0' && c <= '9')
        printf("To cyfra");
    else if (c == '+' || c == '-' || c == '*' || c == '/') 
        printf("To znak arytmetyczny");
    else
        printf("To cos innego");

    return 0;
}