#include <stdio.h>

int main() {
    unsigned ageInYears;
    unsigned ageInMonths;
    unsigned period;

    printf("Podaj wiek (lata miesiace): \n");
    scanf("%d %d", &ageInYears, &ageInMonths);
    printf("Podaj okres w miesiacach:\n");
    scanf("%d", &period);

    ageInYears += period / 12;
    ageInMonths += period % 12;

    if (ageInMonths >= 12) {
        ageInYears += ageInMonths / 12;
        ageInMonths %= 12;
    }

    printf("%d lat(a) %d miesiecy", ageInYears, ageInMonths);

    return 0;
}
