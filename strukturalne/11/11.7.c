#include "../utils.h"

int main(void) {
    int participantCount = 0;
    do {
        printf("Podaj ilosc zawodnikow (max 300): \n");
        scanf("%d", &participantCount);
    } while (participantCount <= 0 && participantCount > 300);

    float* participantTimes = (float*)malloc(participantCount * sizeof(float));

    for (int i = 0; i < participantCount; i++) {
        printf("Podaj czas %d. zawodnika: ", i + 1);
        scanf("%f", participantTimes + i);
    }

    float max = *MaxElementF(participantTimes, participantTimes + participantCount);

    printf("\nNumery zawodnikow ktorzy uzyskali najlepszy czas: \n");
    for (int i = 0; i < participantCount; i++) 
        if (participantTimes[i] == max)
            printf("%d\n", i + 1);

    free(participantTimes);

    return 0;
}