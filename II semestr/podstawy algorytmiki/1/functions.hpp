#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>

void przydzielPamiec1D(int*& tab, int n) {
    tab = new int[n];
}

void przydzielPamiec2D(int**& tab, int w, int k) {
    tab = new int* [w];
    for (int i = 0; i < w; i++)
        tab[i] = new int[k];
}

void wypelnijTablice1D(int* tab, int n, int a, int b) {
    for (int i = 0; i < n; i++)
        tab[i] = a + rand() % (b - a + 1);
}

void wypelnijTablice2D(int** tab, int w, int k, int a, int b) {
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            tab[i][j] = a + rand() % (b - a + 1);
}

void usunTablice1D(int*& tab) {
    delete[] tab;
    tab = nullptr;
}

void usunTablice2D(int**& tab, int w) {
    for (int i = 0; i < w; i++)
        delete[] tab[i];
    delete[] tab;
    tab = nullptr;
}

void wyswietl1D(int* tab, int n) {
    for (int i = 0; i < n; i++)
        std::cout << tab[i] << " ";
    std::cout << '\n';
}

void wyswietl2D(int** tab, int w, int k) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++)
            std::cout << tab[i][j] << " ";
        std::cout << '\n';
    }
}

#endif // FUNCTIONS_HPP