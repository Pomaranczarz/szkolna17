#include <stdio.h>

int main() {   
    int max = 0;
    int temp;

    printf("Podaj liczbe, wpisanie -1 zakonczy wczytywanie\n");
    do {
        scanf("%i", &temp);
        if (temp > max)
            max = temp;
    } while (temp != 0);

    printf("Najwieksza z wprowadzonych liczb: %i", max);
 
    return 0;
}