#include <stdio.h>

double getPayment(unsigned salary, unsigned years) {
    double wyplata;
    if (years < 5)
        wyplata = salary;
    else if (years >= 5 && years <= 10)
        wyplata = salary + salary * years / 100.0;
    else 
        wyplata = salary + salary * 0.15;

    return wyplata;
}

int main() {
    unsigned pensja;
    unsigned lataStazu;
    
    printf("Podaj pensje: \n");
    scanf("%u", &pensja);

    printf("Podaj lata stazu: \n");
    scanf("%u", &lataStazu);

    printf("Calkowita wyplata: %.2f", getPayment(pensja, lataStazu));

    return 0;
}