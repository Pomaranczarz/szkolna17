#include <stdio.h>
#include <math.h>

struct Point2D {
    float x;
    float y;
};

float getDistanceBetweenPoints(struct Point2D p1, struct Point2D p2);
unsigned getPointQuadrant(struct Point2D p);

int main(void) {
    struct Point2D userPoint;
    const struct Point2D origin = {
        .x = 0,
        .y = 0
    };

    printf("Podaj kolejno x i y: \n");
    scanf("%f %f", &userPoint.x, &userPoint.y);

    printf("\nOdleglosc punktu od (0, 0): %f\n", getDistanceBetweenPoints(userPoint, origin));
    unsigned quadrant = getPointQuadrant(userPoint);
    if (quadrant == 5)
        printf("Punkt lezy na jednej z osi\n");
    else
        printf("Punkt lezy w %u cwiartce\n", quadrant);

    return 0;
}

float getDistanceBetweenPoints(struct Point2D p1, struct Point2D p2) {
    return sqrt(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2));
}

unsigned getPointQuadrant(struct Point2D p) {
    if (p.x == 0 || p.y == 0)
        return 5; // lezy na jednej z osi
    else {
        if (p.x > 0) {
            if (p.y > 0)
                return 1;
            else
                return 4;
        } else {
            if (p.y > 0)
                return 2;
            else
                return 3;
        }
    }

}