#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MARKS_PER_STUDENT 5
#define NAME_MAX_LEN 20

struct Student {
    char name[NAME_MAX_LEN];
    char lastname[NAME_MAX_LEN];
    float marks[MARKS_PER_STUDENT];
};

enum ScholarshipType { 
    Increased,
    Normal,
    None,
};

void ReadStdinToStudent(struct Student* student);
float GetAverageMarksForSingleStudent(struct Student* student);
void PrintStudent(struct Student* student);
enum ScholarshipType GetScholarshipType(struct Student* student);


int main(void) {
    size_t num_of_students;
    printf("Podaj liczbe studentow: \n");
    scanf("%llu", &num_of_students);

    struct Student* students = (struct Student*)malloc(num_of_students * sizeof(struct Student));

    for (int i = 0; i < num_of_students; i++)
        ReadStdinToStudent(&students[i]);

    printf("Wszyscy: \n");
    for (int i = 0; i < num_of_students; i++)
        PrintStudent(&students[i]);

    printf("Podwyzszone: \n");
    for (int i = 0; i < num_of_students; i++)
        if (GetScholarshipType(&students[i]) == Increased)
            PrintStudent(&students[i]);

    printf("Normalne: \n");
    for (int i = 0; i < num_of_students; i++)
        if (GetScholarshipType(&students[i]) == Normal)
            PrintStudent(&students[i]);

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

void PrintStudent(struct Student* student) {
    printf("%s %s: [", student->name, student->lastname);
    for (int i = 0; i < MARKS_PER_STUDENT; i++)
        i + 1 == MARKS_PER_STUDENT ? printf("%.2f", student->marks[i]) : printf("%.2f, ", student->marks[i]);

    printf("] srednia: %.2f\n", GetAverageMarksForSingleStudent(student));
}

float GetAverageMarksForSingleStudent(struct Student* student) {
    float sum = 0.f;
    for (int i = 0; i < MARKS_PER_STUDENT; i++)
        sum += student->marks[i];

    return sum / MARKS_PER_STUDENT;
}

bool IsIncreasedScholarship(struct Student* student) {
    for (int i = 0; i < MARKS_PER_STUDENT; i++)
        if (student->marks[i] < 5)
            return false;

    return true;
}

bool IsNormalScholarship(struct Student* student) {
    for (int i = 0; i < MARKS_PER_STUDENT; i++)
        if (student->marks[i] < 4)
            return false;

    return true;
}

enum ScholarshipType GetScholarshipType(struct Student* student) {
    if (IsIncreasedScholarship(student))
        return Increased;
    else if (IsNormalScholarship(student))
        return Normal;
    else
        return None;
}