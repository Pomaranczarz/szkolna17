#include <stdio.h>

void opcja1() {}
void opcja2() {}
void opcja3() {}

int main() {
    printf("==== MENU ====\n");
    printf("1. Opcja 1\n2. Opcja 2\n3. Opcja 3\n4. Wyjscie\n");
    int choice = getchar() - '0';

    switch (choice) {
        case 1:
            opcja1();
            break;
        case 2:
            opcja2();
            break;
        case 3:
            opcja3();
            break;
        case 4:
            return 0;
    }

    return 0;
}