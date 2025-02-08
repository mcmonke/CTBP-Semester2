#include <iostream>
#include "Polynomial/Polynomial.hpp"
#include <cstring>

int main() {

    Polynomial poly1;
    std::cout << "введите полином1: ";
    std::cin >> poly1;
    std::cout << "введеный полином (poly1): " << poly1 << '\n';
    std::cout << "введите полином2: ";
    Polynomial poly2;
    std::cin >> poly2;
    std::cout << "введеный полином (poly2): " << poly2 << '\n';

    Polynomial Summa;
    Summa = poly1 + poly2;
    std::cout << "summa: " << Summa << '\n';
    std::cout << "poly1: " << poly1 << '\n';
    std::cout << "poly2: " << poly2 << '\n';

    Polynomial proizv;
    proizv = poly1 * poly2;
    std::cout << "proizvedenie: " << proizv << '\n';
    std::cout << "poly1: " << poly1 << '\n';
    std::cout << "poly2: " << poly2 << '\n';

    return 0;
}

/*
вводим для проверки
1-й x-1
2-й x+1
*/