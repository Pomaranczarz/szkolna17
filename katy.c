#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
    float alpha;
    printf("Podaj alfe:\n");
    scanf("%f", &alpha);

    float alphaInRadians = alpha * M_PI / 180;
    float sine = sin(alphaInRadians);
    float cosine = cos(alphaInRadians);
    float tangent = tan(alphaInRadians);

    printf("Sin: %f\nCos: %f\nTan: %f", sine, cosine, tangent);

    return 0;
}