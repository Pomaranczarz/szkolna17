#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAME_MAX_LEN 20

struct Student {
    char name[NAME_MAX_LEN];
    char lastname[NAME_MAX_LEN];
    unsigned lucky_number;
};

void ReadStdinToStudent(struct Student* student);
struct Student* GetWinningStudent(struct Student* begin, struct Student* end);
int GetRandomI(int begin, int end);

int main(void) {
    srand(time(NULL));
    
    size_t num_of_students;
    printf("Podaj liczbe studentow: \n");
    scanf("%llu", &num_of_students);

    struct Student* students = (struct Student*)malloc(num_of_students * sizeof(struct Student));

    for (int i = 0; i < num_of_students; i++) {
        ReadStdinToStudent(&students[i]);
        students[i].lucky_number = GetRandomI(0, 100);
    }

    struct Student* winner = GetWinningStudent(students, students + num_of_students);

    printf("Zwyciezca: %s %s [%u]", winner->name, winner->lastname, winner->lucky_number);

    return 0;
}

struct Student* GetWinningStudent(struct Student* begin, struct Student* end) {
    struct Student* winning_student = begin;
    for (struct Student* it = begin; it != end; it++)
        if (it->lucky_number > winning_student->lucky_number)
            winning_student = it;

    return winning_student;
}

int GetRandomI(int begin, int end) {
    return rand() % (end - begin) + begin;
}

void ReadStdinToStudent(struct Student* student) {
    printf("Podaj imie (max 20 znakow): \n");
    scanf("%20s", student->name);
    printf("Podaj nazwisko (max 20 znakow): \n");
    scanf("%20s", student->lastname);
}