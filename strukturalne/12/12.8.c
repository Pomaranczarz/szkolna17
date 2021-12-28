#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 50
#define WORDS_COUNT 5
void BubbleSortStrByStrcmp(char** begin, char** end);

int main(void) {
    char** words = (char**)malloc(WORDS_COUNT * sizeof(char*));
    for (int i = 0; i < WORDS_COUNT; i++) {
        words[i] = (char*)calloc(MAX_WORD_LEN, sizeof(char));
        fgets(words[i], MAX_WORD_LEN, stdin);
    }

    printf("Podane wyrazy: \n");
    for (int i = 0; i < WORDS_COUNT; i++)
        printf("%s", words[i]);

    BubbleSortStrByStrcmp(words, words + WORDS_COUNT);

    printf("W kolejnosci alfabetycznej: \n");
    for (int i = 0; i < WORDS_COUNT; i++)
        printf("%s", words[i]);


    for (int i = 0; i < WORDS_COUNT; i++)
        free(words[i]);

    free(words);

    return 0;
}

void SwapPtr(void** l, void** r) {
    void* temp = *l;
    *l = *r;
    *r = temp;
}

void BubbleSortStrByStrcmp(char** begin, char** end) {
    bool swap_occured;
    int size = end - begin;

    for (int i = 0; i < size; i++) {
        swap_occured = false;

        for (int j = 0; j < size - 1; j++) {
            if (strcmp(begin[j], begin[j + 1]) == 1) {
                SwapPtr(&begin[j], &begin[j + 1]);
                swap_occured = true;
            }
        }

        if (swap_occured == false)
            return;
    }
}