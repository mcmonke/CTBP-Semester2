#include <iostream>
#include <iomanip>
#include "fraction/fraction.hpp"

int fraction::proverka = 1;

int main(){
    int proverka = 1;
    std::cout << "Введите дробь: \n";
    fraction z;
    std::cin >> z;
    if(fraction::getProverka() == 0){
        return 0;
    }
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    fraction f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
    return 0;
}