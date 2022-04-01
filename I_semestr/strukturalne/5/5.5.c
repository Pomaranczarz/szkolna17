#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Podaj kolejno a, b, c oddzielone spacja:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0)
        printf("To nie jest rownanie kwadratowe");
    else {
        const double delta = b * b - 4 * a * c;
        if (delta < 0)
            printf("Rownanie nie ma pierwiastkow rzeczywistych");
        else if (delta == 0) 
            printf("Rownanie ma jedno rozwiazanie rzeczywiste: %f", -b / (2 * a));
        else  {
            const double x1 = (-b + sqrt(delta)) / (2 * a);
            const double x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Rownanie ma dwa rozwiazania rzeczywiste: %f i %f", x1, x2);
        }
    }

    return 0;
}