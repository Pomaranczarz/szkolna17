#include <stdio.h>
#include <math.h>

float getDistanceBetweenPoints(float x1, float  y1, float x2, float y2);
unsigned getPointQuadrant(float x, float  y);

int main(void) {
    float x, y;

    printf("Podaj kolejno x i y: \n");
    scanf("%f %f", &x, &y);

    float dystans = getDistanceBetweenPoints(x, y, 0.0, 0.0);

    printf("\nOdleglosc punktu od (0, 0): %f %p\n", dystans, &dystans);
    unsigned quadrant = getPointQuadrant(x, y);
    printf("\nAdres numeru cwiartki: %p", &quadrant);
    if (quadrant == 5)
        printf("Punkt lezy na jednej z osi\n");
    else
        printf("Punkt lezy w %u cwiartce\n", quadrant);

    return 0;
}

float getDistanceBetweenPoints(float x1, float  y1, float x2, float y2) {
    float wynik = sqrt(powf(x2 - x1, 2) + powf(y2 - y1, 2));
    printf("Adres wyniku w funkcji: %p", &wynik);

    return wynik;
}

unsigned getPointQuadrant(float x, float  y) {
    if (x == 0 || y == 0)
        return 5; // lezy na jednej z osi
    else {
        if (x > 0) {
            if (y > 0)
                return 1;
            else
                return 4;
        } else {
            if (y > 0)
                return 2;
            else
                return 3;
        }
    }

}