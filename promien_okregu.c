#include <stdio.h>
#include <math.h>

#define _USE_MATH_DEFINES

struct Point2D {
    float x;
    float y;
};

float getPointsDistance(struct Point2D* a, struct Point2D* b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - b->x, 2));
}

int main() {
    struct Point2D A;
    struct Point2D B;

    printf("Podaj oddzielone spacja wspolrzedne punktu A:\n");
    scanf("%f %f", &A.x, &A.y);
    printf("Podaj oddzielone spacja wspolrzedne punktu B:\n");
    scanf("%f %f", &B.x, &B.y);

    float radius = getPointsDistance(&A, &B);
    printf("Obwod wynosi %f", 2 * M_PI * radius);

    return 0;
}