#include <stdio.h>
#include <stdbool.h>

struct Point2D {
    double x;
    double y;
};

bool isInsideSquare(struct Point2D p) {
    return p.x <= 1 && p.x >= -1 && p.y <= 1 && p.y >= -1;
}

int main() {
    struct Point2D p1;
    printf("Podaj x i y: ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Czy jest wewnatrz kwadratu: ");
    if (isInsideSquare(p1)) {
        printf("TAK\n");
    } else {
        printf("NIE\n");
    }
}