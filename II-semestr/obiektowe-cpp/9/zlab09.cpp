#include "zlab09.hpp"

void ZLab09::rozmiary() {
    std::cout << "--->Rozmiary" << std::endl;
    std::cout << "    int: " << sizeof(int) << std::endl
        << "    int*: " << sizeof(int*) << std::endl
        << "    int**: " << sizeof(int**) << std::endl
        << "    int***: " << sizeof(int***) << std::endl
        << "    Glon: " << sizeof(Alga) << std::endl
        << "    Glon*: " << sizeof(Alga*) << std::endl
        << "    Glon**: " << sizeof(Alga**) << std::endl
        << "    UstawieniaSymulacji: " << sizeof(SimulationSettings) << std::endl
        << "    UstawieniaSymulacji*: " << sizeof(SimulationSettings*) << std::endl
        << "    long: " << sizeof(long) << std::endl << std::endl;
}

void ZLab09::skalar() {
    std::cout << "--->Skalar" << std::endl;
    wskInt1D = new int;
    *wskInt1D = 5;
    std::cout << "*wsikInt1D = " << *wskInt1D << std::endl
        << "*wskInt1D + 3 = " << *wskInt1D + 3 << std::endl
        << "adres zapisany w wskInt1D = " << wskInt1D << std::endl << std::endl;

    delete wskInt1D;
}

void ZLab09::tablica1D() {
    std::cout << "--->Tablica 1D" << std::endl;
    wskInt1D = new int[3];

    wskInt1D[0] = 2;
    *(wskInt1D + 1) = 5;
    wskInt1D[2] = 7;

    std::cout << *wskInt1D << " " << wskInt1D[1]
        << " " << *(wskInt1D + 2) << std::endl;

    int* iter = wskInt1D;
    std::cout << *iter << " ";
    iter++;
    std::cout << *iter << " ";
    iter++;
    std::cout << *iter << std::endl;

    delete[] wskInt1D;
}

void ZLab09::tablica2D(int w, int k) {
    std::cout << "--->Tablica 2D" << std::endl;

    wskInt2D = new int* [w];

    for (int i = 0; i < w; ++i)
        wskInt2D[i] = new int[k];

    for (int i = 0; i < w; ++i)
        for (int j = 0; j < k; ++j)
            wskInt2D[i][j] = i + j;

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j)
            std::cout << wskInt2D[i][j] << " ";
        std::cout << std::endl;
    }

    for (int i = 0; i < w; ++i)
        delete[] wskInt2D[i];

    delete[] wskInt2D;
}

void ZLab09::referencja() {
    std::cout << "---> Referencje" << std::endl;

    int a = 1, b = 5;
    std::cout << "a = " << a << " b = " << b << std::endl;

    int& refInt = a;
    std::cout << "a = " << a << " b = " << b << std::endl;

    refInt = b;
    std::cout << "a = " << a << " b = " << b << std::endl;

    std::cout << "To samo, ale na wskaznikach" << std::endl;
    int A = 1, B = 5;
    std::cout << "A = " << A << " B = " << B << std::endl;

    int* wskInt = &A;
    std::cout << "A = " << A << " B = " << B << std::endl;

    wskInt = &B;
    std::cout << "A = " << A << " B = " << B << std::endl;

    Alga alga;
    Alga& refAlga = alga;

    std::cout << "Rozmiary" << std::endl
        << "sizeof(int&)=" << sizeof(int&) << std::endl
        << "sizeof(refInt)= " << sizeof(refInt) << std::endl
        << "sizeof(Alga&)=" << sizeof(Alga&) << std::endl
        << "sizeof(refAlga)= " << sizeof(refAlga) << std::endl;
}