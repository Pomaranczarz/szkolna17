#include <stdio.h>
#include <math.h>

int main() {
    float x;
    printf("Podaj x:\n");
    scanf("%f", &x);
    printf("%f", 10 * cos(x) - 0.1 * pow(x, 2) + sin(x) + sqrt(4 * pow(x, 2) + 7));
    printf("%f", log10(x + 5) + exp(x + 1) - abs(tan(x) + 1));
    float alpha;
    printf("Podaj alfe:\n");
    scanf("%f", &alpha);
    printf("%f", (pow(sin(alpha), 2) + 0.5) / (cos(pow(alpha, 4)) + pow(tan(pow(alpha, 2)), 2)));
    float beta;
    printf("Podaj bete:\n");
    scanf("%f", &beta);
    printf("%f", sqrt(abs(5 * sin(pow(beta, 5)) + 1) / ( 3.5 * pow(sin(beta) + cos(beta), 2))));
    return 0;
}
