#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char zdanie[50];
    printf("Podaj zdanie: \n");
    fgets(zdanie, 50, stdin);

    unsigned histogram['z' - 'a'] = { 0 };
    unsigned i, num_count = 0;

    for (i = 0; i < strlen(zdanie); i++) {
        if (isalpha(zdanie[i]))
            histogram[tolower(zdanie[i]) - 'a']++;
        if (isdigit(zdanie[i]))
            num_count++;
    }

    for (i = 0; i < 'z' - 'a'; i++)
        printf("%c: %u\n", 'a' + i, histogram[i]);

    printf("\nCyfr w podanym zdaniu: %u", num_count);
    return 0;
}