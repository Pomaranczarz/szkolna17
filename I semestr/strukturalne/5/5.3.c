#include <stdio.h>
#include <math.h>

double f1(double alpha) {
    return 1 - sin(alpha);
}

double f2(double alpha) {
    return 0.5 * (1 + sin(alpha));
}

double f3(double alpha) {
    return  sqrt(alpha * alpha + 1);
}

double funkcja1(double alpha) {
    int t;
    printf("Podaj t:\n");
    scanf("%d", &t);

    if (t == 8)
        return f1(alpha);
    else if (t == 0 || t == 1 || t == 2 || t == 3) 
        return f2(alpha);
    else if (t == 4 || t == 6 || t == 7)
        return f3(alpha);
    else
        return 0;
}

double funkcja2(double alpha) {
    int t;
    printf("Podaj t:\n");
    scanf("%d", &t);

    switch (t) {
        case 8:
            return f1(alpha);
        case 0:
        case 1:
        case 2:
        case 3:
            return f2(alpha);
        case 4:
        case 6:
        case 7:
            return f3(alpha);
        default:
            return 0;
    }
}

int main() {
    double alpha;
    printf("Podaj alpha:\n");
    scanf("%lf", &alpha);

    printf("Wynik dzialania funkcja1(%f) = %f\n", funkcja1(alpha), alpha);
    printf("Wynik dzialania funkcja2(%f) = %f\n", funkcja1(alpha), alpha);
    return 0;
}