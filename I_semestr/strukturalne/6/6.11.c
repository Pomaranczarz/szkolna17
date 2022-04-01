#include <stdio.h>

int main() {
    unsigned i;

    for (i = 0; i < 'z' - 'a'; i++) {
       printf("%c->%i\t%c->%i\n", 'A' + i, 'A' + i, 'a' + i, 'a' + i); 
    }

    return 0;
}