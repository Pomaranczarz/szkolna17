#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SUBJECT_NAME_LEN 20
#define MAX_LECTURER_NAME_LEN 40

struct ScheduleEntry {
    enum WeekDay { 
        MONDAY, 
        TUESDAY, 
        WEDNESDAY, 
        THURSDAY, 
        FRIDAY, 
        SATURADY, 
        SUNDAY,
        NONE,
    } week_day;

    unsigned start_time;
    unsigned end_time;
    unsigned room_nr;
    char subject[MAX_SUBJECT_NAME_LEN];
    char lecturer[MAX_LECTURER_NAME_LEN];
};

void ReadStdinToScheduleEntry(struct ScheduleEntry* scheduleEntry);
void PrintMatching(
    struct ScheduleEntry* begin, 
    struct ScheduleEntry* end, 
    bool(*predicate)(struct ScheduleEntry)
);

bool IsLectureInMonday(struct ScheduleEntry scheduleEntry) {
    return scheduleEntry.week_day == MONDAY;
}

bool IsProgramowanie(struct ScheduleEntry scheduleEntry) {
    char* ignore_case_str = (char*)malloc(strlen(scheduleEntry.subject) * sizeof(char));
    for (int i = 0; i < strlen(scheduleEntry.subject); i++)
        ignore_case_str[i] = tolower(scheduleEntry.subject[i]);

    int cmp_result =  strcmp(ignore_case_str, "programowanie");

    free(ignore_case_str);
    return cmp_result == 0;
}

bool StartsAt8(struct ScheduleEntry scheduleEntry) {
    return scheduleEntry.start_time == 8;
}

int main(void) {
    size_t num_of_lectures;
    printf("Podaj liczbe zajec: \n");
    scanf("%llu", &num_of_lectures);

    struct ScheduleEntry* scheduleEntries = (struct ScheduleEntry*)malloc(num_of_lectures * sizeof(struct ScheduleEntry));

    for (int i = 0; i < num_of_lectures; i++)
        ReadStdinToScheduleEntry(&scheduleEntries[i]);

    printf("Odbywajce sie w poniedzialek: \n");
    PrintMatching(scheduleEntries, scheduleEntries + num_of_lectures, IsLectureInMonday);
    printf("\nZajecia z programowania: \n");
    PrintMatching(scheduleEntries, scheduleEntries + num_of_lectures, IsProgramowanie);
    printf("\nOdbywajace sie o 8: \n");
    PrintMatching(scheduleEntries, scheduleEntries + num_of_lectures, StartsAt8);

    free(scheduleEntries);

    return 0;   
}

enum WeekDay StrToWeekDay(const char* str) {
    char* ignore_case_str = (char*)malloc(strlen(str) * sizeof(char));
    for (int i = 0; i < strlen(str); i++)
        ignore_case_str[i] = tolower(str[i]);

    enum WeekDay result;
    if (strcmp(ignore_case_str, "poniedzialek") == 0)       result = MONDAY;
    else if (strcmp(ignore_case_str, "wtorek") == 0)        result = TUESDAY;
    else if (strcmp(ignore_case_str, "sroda") == 0)         result = WEDNESDAY;
    else if (strcmp(ignore_case_str, "czwartek") == 0)      result = THURSDAY;
    else if (strcmp(ignore_case_str, "piatek") == 0)        result = FRIDAY;
    else if (strcmp(ignore_case_str, "sobota") == 0)        result = SATURADY;
    else if (strcmp(ignore_case_str, "niedziela") == 0)     result = SUNDAY;
    else                                                    result = NONE;

    free(ignore_case_str);
    return result;
}

const char* WeekDayToStr(enum WeekDay weekDay) {
    switch (weekDay) {
        case MONDAY:        return "poniedzialek";
        case TUESDAY:       return "wtorek";
        case WEDNESDAY:     return "sroda";
        case THURSDAY:      return "czwartek";
        case FRIDAY:        return "piatek";
        case SATURADY:      return "sobota";
        case SUNDAY:        return "niedziela";
        default: 
            perror("Fatal error");
            exit(EXIT_FAILURE);
    }
}

void PrintScheduleEntry(struct ScheduleEntry scheduleEntry) {
    printf("%s, %s [sala %u] \t%u - %u, %s\n", 
        scheduleEntry.subject,
        scheduleEntry.lecturer,
        scheduleEntry.room_nr,
        scheduleEntry.start_time,
        scheduleEntry.end_time,
        WeekDayToStr(scheduleEntry.week_day)
    );
}

void PrintMatching(
    struct ScheduleEntry* begin, 
    struct ScheduleEntry* end, 
    bool(*predicate)(struct ScheduleEntry)
) {
    for (struct ScheduleEntry* it = begin; it != end; it++) 
        if (predicate(*it))
            PrintScheduleEntry(*it);
}

void ReadStdinToScheduleEntry(struct ScheduleEntry* scheduleEntry) {
    char day[13] = { '\0' };
    printf("Podaj dzien tygdonia: \n");
    scanf("%s", day);
    enum WeekDay weekDay = StrToWeekDay(day);
    if (weekDay == NONE) {
        perror("Podano nieprawidlowy wartosc dla dnia");
        exit(EXIT_FAILURE);
    }
    scheduleEntry->week_day = weekDay;

    printf("Podaj godzine rozpoczecia: \n");
    scanf("%u", &scheduleEntry->start_time);
    printf("Podaj godzine zakonczenia: \n");
    scanf("%u", &scheduleEntry->end_time);
    printf("Podaj numer sali: \n");
    scanf("%u", &scheduleEntry->room_nr);
    printf("Podaj nazwe przemdiotu (max %d znakow): \n", MAX_SUBJECT_NAME_LEN);
    scanf("%s", scheduleEntry->subject);
    printf("Podaj wykladowce (max %d znakow): \n", MAX_LECTURER_NAME_LEN);
    scanf("%s", scheduleEntry->lecturer);
}