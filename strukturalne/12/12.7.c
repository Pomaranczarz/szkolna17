#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SINGLE_INPUT_LEN 120
#define EXIT_STR "quit"

bool IsExitStr(const char* str);

int main(void) {
    char buff[MAX_SINGLE_INPUT_LEN];
    do {
        fgets(buff, MAX_SINGLE_INPUT_LEN, stdin);
    } while (!IsExitStr(buff));

    return 0;
}

bool IsExitStr(const char* str) {
    for (int i = 0, len = strlen(EXIT_STR); i < len; i++)
        if (str[i] != EXIT_STR[i])
            return false;

    return true;
}