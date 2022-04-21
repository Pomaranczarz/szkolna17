#pragma once

#include <iostream>
#include "../7/Entities.hpp"
#include "../4/Settings.hpp"

class ZLab09
{
public:
    void rozmiary();
    void skalar();
    void tablica1D();
    void tablica2D(int, int);
    void referencja();

    int* wskInt1D{ nullptr };
    int** wskInt2D{ nullptr };
};