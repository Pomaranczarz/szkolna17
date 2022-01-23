#include <stdio.h>

double sredniaWhile(unsigned n);
double sredniaDoWhile(unsigned n);

int main() {
    sredniaDoWhile(3);
    sredniaWhile(3);

    return 0;
}

double sredniaWhile(unsigned n) {
    double sum = 0.0;
    const unsigned num_of_elemets = n;
    double temp;

    while (n--) {
        printf("Podaj liczbe: \n");
        scanf("%lf", &temp);
        sum += temp;
    }

    return sum / num_of_elemets;
}

double sredniaDoWhile(unsigned n) {
    double sum = 0.0;
    const unsigned num_of_elemets = n;
    double temp;
    
    do {
        printf("Podaj liczbe: \n");
        scanf("%lf", &temp);
        sum += temp;
    } while (--n);

    return sum / num_of_elemets;
}
