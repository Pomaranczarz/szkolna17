#include <iostream>

#include "Prostokat.hpp"

int main() {
    Rectangle p1;
    Rectangle p2 { "koc", 1.4, 2.2 };
    Rectangle p3 { "pulapka", -2, -3 };

    std::cout.precision(2);
    std::cout << p1.toString() << '\n';
    std::cout << p2.toString() << '\n';
    std::cout << p3.toString() << '\n';

    if (!p3.setSize(2, 3))
        std::cout << "Nie udało się ustawić rozmiaru prostokata.\n";

    std::cout << std::boolalpha;
    std::cout << p3.toString() << '\n';

    std::cout << "Uzycie metod obiektu: \n";
    std::cout << "Nazwa: " << p1.getName() << '\n';
    std::cout << "Poprawny: " << p1.isValid() << '\n';
    std::cout << "Pole: " << p1.getArea() << '\n';
    std::cout << "Obwod: " << p1.getPerimeter() << '\n';
}