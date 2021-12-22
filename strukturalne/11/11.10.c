#include "../utils.h"

float* getDistances(struct Point2Di* points, int count);

int main(void) {
    int n;
    printf("Podaj n: \n");
    scanf("%d", &n);

    struct Point2Di* punkty = (struct Point2Di*)malloc(sizeof(struct Point2Di) * n);

    for (int i = 0; i < n; i++) {
        punkty[i].x = GetRandomI(-20, 20);
        punkty[i].y = GetRandomI(-20, 20);
    }

    printf("Punkty: \n");
    for (int i = 0; i < n; i++)
        printf("(%d, %d)\n", punkty[i].x, punkty[i].y);

    float* distances = getDistances(punkty, n);
    printf("\nOdleglosci: \n");
    PrintArrayF(distances, n, ", ");

    return 0;
}

float* getDistances(struct Point2Di* points, int count) {
    struct Point2Di origin = { .x = 0, .y = 0};
    float* distances = (float*)malloc(count * sizeof(float));
    for (int i = 0; i < count; i++) 
        distances[i] = GetDistanceBetweenPointsI(points[i], origin);

    return distances;
}
