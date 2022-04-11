#include "../utils.h"

#define FILENAME "temperatury.txt"
#define TEMPERATURES_COUNT 50

void SaveTemperaturesToFile(const char* filename, float* temperatures, size_t count);
void ReadTemperaturesFromFile(const char* filename, float* temperatures, size_t count);

int main(void) {
    srand(time(NULL));

    float temperatures[TEMPERATURES_COUNT];
    for (int i = 0; i < TEMPERATURES_COUNT; i++)
        temperatures[i] = (float)GetRandomI(-5, 15) + ((float)(GetRandomI(0, 100) / 100.f));

    SaveTemperaturesToFile(FILENAME, temperatures, TEMPERATURES_COUNT);

    float temperatures_from_file[TEMPERATURES_COUNT];
    ReadTemperaturesFromFile(FILENAME, temperatures_from_file, TEMPERATURES_COUNT);

    printf("Srednia temperatura: %f",
        AverageF(temperatures_from_file, temperatures_from_file + TEMPERATURES_COUNT)
    );

    return 0;
}

void SaveTemperaturesToFile(const char* filename, float* temperatures, size_t count) {
    FILE* out = fopen(filename, "w");
    if (out == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    for (int i = 0; i < count; i++)
        fprintf(out, "%f\n", temperatures[i]);

    fclose(out);
}

void ReadTemperaturesFromFile(const char* filename, float* temperatures, size_t count) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    for (int i = 0; i < count; i++)
        fscanf(in, "%f", &temperatures[i]);

    fclose(in);
}