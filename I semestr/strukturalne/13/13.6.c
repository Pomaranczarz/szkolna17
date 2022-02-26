#include <stdio.h>
#include <stdlib.h>

#define MARKS_PER_STUDENT 5
#define NAME_MAX_LEN 20

struct Student {
    char name[NAME_MAX_LEN];
    char lastname[NAME_MAX_LEN];
    float marks[MARKS_PER_STUDENT];
};

void ReadStdinToStudent(struct Student* student);
float GetAverageMarksForSingleStudent(struct Student* student);
float GetAverageMarksForStudentsInRange(struct Student* begin, struct Student* end);

int main(void) {
    size_t num_of_students;
    printf("Podaj liczbe studentow w grupie: \n");
    scanf("%llu", &num_of_students);

    struct Student* students = (struct Student*)malloc(num_of_students * sizeof(struct Student));

    for (int i = 0; i < num_of_students; i++)
        ReadStdinToStudent(&students[i]);

    for (int i = 0; i < num_of_students; i++) 
        printf("%s %s: %.2f\n", 
            students[i].name, 
            students[i].lastname, 
            GetAverageMarksForSingleStudent(&students[i])
        );

    printf("Srednia wszystkich: %.2f", GetAverageMarksForStudentsInRange(students, students + num_of_students));
    
    free(students);

    return 0;
}

void ReadStdinToStudent(struct Student* student) {
    printf("Podaj imie (max 20 znakow): \n");
    scanf("%20s", student->name);
    printf("Podaj nazwisko (max 20 znakow): \n");
    scanf("%20s", student->lastname);

    for (int i = 0; i < MARKS_PER_STUDENT; i++) {
        printf("Podaj %d. ocene: \n", i + 1);
        scanf("%f", &student->marks[i]);
    }
}

float GetAverageMarksForSingleStudent(struct Student* student) {
    float sum = 0.f;
    for (int i = 0; i < MARKS_PER_STUDENT; i++)
        sum += student->marks[i];

    return sum / MARKS_PER_STUDENT;
}

float GetAverageMarksForStudentsInRange(struct Student* begin, struct Student* end) {
    float sum = 0.f;
    for (struct Student* it = begin; it != end; it++)
        for (int i = 0; i < MARKS_PER_STUDENT; i++)
            sum += it->marks[i];

    return sum / (MARKS_PER_STUDENT * (end - begin));
}