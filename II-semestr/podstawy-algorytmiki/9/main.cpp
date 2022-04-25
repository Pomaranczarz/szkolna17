#include <iostream>
#include <fstream>
#include <ctime>
#include "Stack.hpp"

#define ZAD1
// #define ZAD2
// #define ZAD3

void print_menu() {
    std::cout << "1. Sprawdzenie czy stos jest pusty\n2. Dodanie losowej liczby z zakresu 1-10 do stosu\n";
    std::cout << "3. Usuniecie elemetu ze stosu\n4. Wyswietlenie ostatniego elementu ze stosu\n";
    std::cout << "5. Wyczyszczenie stosu\n6. Wyjscie z programu\n";
}

std::string decTo(int value, int baseTo);

int main() {
#ifdef ZAD1
    srand(time(0));
    int choice;
    Stack<int> stack;

    do {
        print_menu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (stack.empty()) std::cout << "Stos jest pusty\n";
            else std::cout << "Stos nie jest pusty\n";
            break;
        case 2:
            stack.push(rand() % 10 + 1);
            std::cout << "Wylosowano i wstawiono: " << stack.top() << '\n';
            break;
        case 3:
            try { std::cout << "Usunieto: " << stack.pop() << '\n'; }
            catch(std::out_of_range& e) { std::cout << "Stos jest pusty\n"; }
            break;
        case 4:
            std::cout << "Ostatni element stosu: " << stack.top() << '\n';
            break;
        case 5: 
            stack.clear();
            std::cout << "Usunieto wszystkie elementy ze stosu\n";
            break;
        }

    } while (choice != 6);
#endif
#ifdef ZAD2
    Stack<char> stack;

    std::ifstream input{ "znaki1.txt" };
    if (!input.good()) {
        std::cerr << "Blad pliku\n";
        return EXIT_FAILURE;
    }

    for (char c = input.get(); c != EOF; c = input.get())
        stack.push(c);

    std::ofstream output{ "wynik.txt" };
    while (!stack.empty())
        output << stack.pop();

#endif
#ifdef ZAD3
    int input, baseTo;
    std::cout << "Podaj liczbe w systemie dziesietnym:\n";
    std::cin >> input;

    std::cout << "Podaj podstawe systemu na ktory chcesz przekonwertowac:\n";
    std::cin >> baseTo;

    std::cout << "Wynik: " << decTo(input, baseTo) << '\n';

#endif
}

char getValueInBase(int value, int base) {
    if (value >= 0 && value <= 9)
        return '0' + value;
    else
        return 'A' + value - 10;
}

std::string decTo(int value, int baseTo) {
    Stack<char> stack;

    while (value) {
        stack.push(getValueInBase(value % baseTo, baseTo));
        value /= baseTo;
    }

    std::string result;
    while (!stack.empty())
        result += stack.pop();

    return result;
}
