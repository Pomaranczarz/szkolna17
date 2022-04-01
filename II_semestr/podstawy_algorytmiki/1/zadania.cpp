#include "functions.hpp"

void zadanie12();
void zadanie13();
void zadanie14();
void zadanie15();

int main() {
    char answer{ '\0' };
    bool is_running{ true };

    while (is_running) {
        std::cout << "Wybierz opcje: \n1. Zadanie 1.2\n2. Zadanie 1.3\n3. Zadanie 1.4\n4. Zadanie 1.5\n5. Wyjscie\n";
        std::cin >> answer;

        switch (answer) {
        case '1': zadanie12();          break;
        case '2': zadanie13();          break;
        case '3': zadanie14();          break;
        case '4': zadanie15();          break;
        default: is_running = false;    break;
        }
    }
}

int min1D(int* tab, int n) {
    int min = tab[0];
    for (int i = 1; i < n; i++)
        if (tab[i] < min)
            min = tab[i];
    return min;
}

bool is_prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void zadanie12() {
    int n{ 0 }, a{ 0 }, b{ 0 };
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> n;
    std::cout << "Podaj przedzial <a,b>: ";
    std::cin >> a >> b;

    int* tab{ nullptr };
    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, a, b);
    wyswietl1D(tab, n);

    int min = min1D(tab, n);
    std::cout << "Najmniejszy element tablicy to: " << min << '\n';

    if (is_prime(min)) std::cout << "Najmniejsza liczba jest pierwsza\n";
    else std::cout << "Najmniejsza liczba nie jest pierwsza\n";

    usunTablice1D(tab);
}

void zadanie13() {
    int n{ 0 };
    std::cout << "Podaj rozmiar tablicy: \n";
    std::cin >> n;

    int* tab{ nullptr };
    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, 0, 9);
    wyswietl1D(tab, n);

    int histogram[10]{ 0 };
    for (int i = 0; i < n; i++)
        ++histogram[tab[i]];

    for (int i = 0; i < 10; i++)
        std::cout << i << ": " << histogram[i] << '\n';

    usunTablice1D(tab);
}

int max2D(int** tab, int n, int m) {
    int max = tab[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tab[i][j] > max)
                max = tab[i][j];
    return max;
}

int get_digits_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void zadanie14() {
    int n{ 0 }, m{ 0 }, a{ 0 }, b{ 0 };
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> n >> m;
    std::cout << "Podaj przedzial <a,b>: ";
    std::cin >> a >> b;

    int** tab{ nullptr };
    przydzielPamiec2D(tab, n, m);
    wypelnijTablice2D(tab, n, m, a, b);
    wyswietl2D(tab, n, m);

    int max = max2D(tab, n, m);
    std::cout << "Najwiekszy element tablicy to: " << max << '\n';
    std::cout << "Suma cyfr znalezionej liczby to: " << get_digits_sum(max) << '\n';

    usunTablice2D(tab, n);
}

void zadanie15() {
    int n{ 0 };
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> n;

    int** tab{ nullptr };
    przydzielPamiec2D(tab, n, n);
    wypelnijTablice2D(tab, n, n, 7, 122);
    wyswietl2D(tab, n, n);

    int sum_above = 0, sum_below = 0;
    for (int i = 0; i < n; i++) {
        sum_above += tab[i][i];
        sum_below += tab[i][n - i - 1];
    }
    std::cout << "Srednia arytmetyczna elementow znajdujacych sie nad glowna przekatna to: " << 1.f * sum_above / n << '\n';
    std::cout << "Srednia arytmetyczna elementow znajdujacych sie pod glowna przekatna to: " << 1.f * sum_below / n << '\n';

    usunTablice2D(tab, n);
}