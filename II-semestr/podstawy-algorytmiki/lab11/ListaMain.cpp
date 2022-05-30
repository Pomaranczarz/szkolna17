#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List.hpp"

void print_menu();
void add_at_given_position(List<int>& list);
void remove_at_given_position(List<int>& list);
void print_min(List<int>& list);

int main()
{
    srand(time(nullptr));
    List<int> list;
    int choice;

    do
    {
        std::cout << '\n';
        print_menu();
        std::cout << '\n';
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << std::boolalpha;
            std::cout << list.empty() << '\n';
            break;
        case 2:
            list.push_back(rand() % 100);
            std::cout << "Dodano: " << list.back() << '\n';
            break;
        case 3:
            list.push_front(rand() % 100);
            std::cout << "Dodano: " << list.front() << '\n';
            break;
        case 4:
            add_at_given_position(list);
            break;
        case 5:
            list.pop_back();
            break;
        case 6:
            list.pop_front();
            break;
        case 7:
            remove_at_given_position(list);
            break;
        case 8:
            for (auto& elem : list)
                std::cout << elem << " ";
            break;
        case 9:
            for (auto it = list.rbegin(); it != list.rend(); ++it)
                std::cout << *it << " ";
            break;
        case 10:
            print_min(list);
            break;
        case 11:
            list.clear();
            break;
        default:
            break;
        }
        std::cout << '\n';

    } while (choice != 12);
}

void print_menu()
{
    std::cout << "1. Sprawdzenie czy lista jest pusta\n2. Dodanie elementu na koniec listy\n3. Dodanie elementu na poczatek listy\n";
    std::cout << "4. Dodanie elementu na okreslona pozycje\n5. Usuniecie elementu z konca listy\n6. Usuniecie elementu z poczatku listy\n";
    std::cout << "7. Usuniecie elementu z okreslonej pozycji\n8. Wyswietlenie elementow od poczatku do konca\n9. Wyswietlenie elementow od konca do poczatku\n";
    std::cout << "10. Znalezienie elementu minimalnego\n11. Usuniecie listy\n12. Wyjscie";
}

void add_at_given_position(List<int>& list) {
    int pos;
    std::cout << "Podaj pozycje: \n";
    std::cin >> pos;

    auto it = list.begin();
    std::advance(it, pos);
    list.insert(it, rand() % 100);
}

void remove_at_given_position(List<int>& list) {
    int pos;
    std::cout << "Podaj pozycje: \n";
    std::cin >> pos;

    auto it = list.begin();
    std::advance(it, pos);

    list.erase(it);
}

void print_min(List<int>& list) {
    int min = list.front();
    int min_pos = 0;
    int pos = 0;
    for (auto it = list.begin(); it != list.end(); it++, pos++) {
        if (*it < min) {
            min_pos = pos;
            min = *it;
        }
    }

    std::cout << "Min: " << min << " [" << min_pos << "] \n"; 
}
