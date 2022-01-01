#include <stdio.h>
#include <stdlib.h>

#define SWIM_FILENAME "plywanie.txt"
#define RUN_FILENAME "bieganie.txt"

void ReadFile(const char* filename);
void SaveToFile(const char* filename, const char* name, const char* lastname, unsigned points);
void Print3Best(const char* filename);

int main(void) {
    printf("Wyniki plywania: \n");
    ReadFile(SWIM_FILENAME);
    printf("\nWyniki biegania: \n");
    ReadFile(RUN_FILENAME);
    printf("\n3 najlepsze wyniki z plywania: \n");
    Print3Best(SWIM_FILENAME);
    printf("\n3 najlepsze wyniki z biegania: \n");
    Print3Best(RUN_FILENAME);

    return 0;
}

void ReadFile(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    char name[30];
    char lastname[30];
    unsigned points;

    while (fscanf(in, "%s %s %u\n", name, lastname, &points) == 3) 
        printf("%s %s: %u\n", name, lastname, points);

    fclose(in);
}

void SaveToFile(const char* filename, const char* name, const char* lastname, unsigned points) {
    FILE* out = fopen(filename, "a");
    if (out == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    fprintf(out, "%s %s %u", name, lastname, points);

    fclose(out);
}

struct Competitor  {
    char name[30];
    char lastname[30];
    unsigned points;
};

int CompetitorCmp(const void* l, const void* r) {
    struct Competitor* l_ = (struct Competitor*)l;
    struct Competitor* r_ = (struct Competitor*)r;
    if (l_->points > r_->points) return 1;
    else if (r_->points > l_->points) return -1;
    else return 0;
}

void Print3Best(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    char c;
    unsigned records_count = 0;
    while ((c = getc(in)) != EOF) 
        if (c == '\n')
            records_count++;
    
    fseek(in, 0, SEEK_SET);

    struct Competitor* records = (struct Competitor*)malloc(records_count * sizeof(struct Competitor));
    unsigned records_index = 0;

    while (fscanf(in, "%s %s %u", 
        records[records_index].name, records[records_index].lastname, &records[records_index].points) == 3
    ) records_index++;
    
    qsort(records, records_count, sizeof(struct Competitor), CompetitorCmp);
    records_index--;

    for (int i = 0; i < 3; i++) {
        printf("Imie: %s\tNazwisko: %s\tPunkty: %u\n", 
            records[records_index].name, records[records_index].lastname, records[records_index].points
        );
        records_index--;
    }

    free(records);
    fclose(in);
}