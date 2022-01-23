#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_OFFSET 'z' - 'a'
#define MAX_WORD_LEN 50
#define EXIT_STR "quit"

void Cipher(char* begin, char* end, size_t offset);
bool IsExitStr(const char* str);
void ClearStr(char* begin, char* end);

int main(void) {
    char word[MAX_WORD_LEN] = { '\0' };
    size_t offset;
    while(true) {
        printf("Podaj napis: \n");
        fgets(word, MAX_WORD_LEN, stdin);

        if (IsExitStr(word))
            break;

        printf("Podaj przesuniecie: \n");
        scanf("%llu", &offset);

        printf("Podano: %s", word);
        Cipher(word, word + strlen(word), offset);
        printf("Zaszyfrowane szyfrem cezara (przesuniecie = %llu): %s", offset, word);

        ClearStr(word, word + MAX_WORD_LEN);
        fflush(stdin);
    } 

    return 0;
}

bool IsExitStr(const char* str) {
    for (int i = 0, len = strlen(EXIT_STR); i < len; i++)
        if (str[i] != EXIT_STR[i])
            return false;

    return true;
}

void ClearStr(char* begin, char* end) {
    while (begin != end) {
        *begin = '\0';
        begin++;
    }
}

void MoveCharBy(char* c, size_t offset) {
    if (!isalpha(*c))
        return;

    if (offset > MAX_OFFSET)
        offset = offset % MAX_OFFSET;

    if (islower(*c)) {
        if (*c + offset > 'z')
            *c = 'a' + (*c + offset) - 'z';
        else 
            *c += offset;
    } else  {
        if (*c + offset > 'Z')
            *c = 'A' + (*c + offset) - 'Z';
        else 
            *c += offset;
    }
}

void Cipher(char* begin, char* end, size_t offset) {
    for (char* it = begin; it != end; it++)
        MoveCharBy(it, offset);
}