#include <iostream>
#include "mymath/mymath.h"
#include "mymath2/mymath2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Сумма 13+33 равна"<< std::endl;
    std::cout << mymath::sum(13, 33) << std::endl;
    std::cout << "Разница 87 и 21 равна"<<std::endl;
    std::cout << mymath::minus(87, 21) << std::endl;
    std::cout << "Произведение 11 и 12 равно"<<std::endl;
    std::cout << mymath::proizvedenie(11, 12) << std::endl;
    std::cout << "Сумма элементов числа 5"<<std::endl;
    std::cout << mymath2::sum_elem(5) << std::endl;
    return 0;
}