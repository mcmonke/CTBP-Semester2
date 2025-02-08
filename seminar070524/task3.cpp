#include <iostream>

class Mammals {
public:
    void print() {
        std::cout << "Я - млекопитающее.\n";
    }
};

class MarineAnimals {
public:
    void print() {
        std::cout << "Я - морское животное.\n";
    }
};

class BlueWhale : public Mammals, public MarineAnimals {
public:
    void print() {
        std::cout << "Я принадлежу к обеим категориям: Млекопитающие и Морские животные.\n";
    }
};

int main() {
    Mammals mammal;
    MarineAnimals marine;
    BlueWhale blueWhale;

    mammal.print();
    marine.print();
    blueWhale.print();

    blueWhale.Mammals::print();
    blueWhale.MarineAnimals::print();

    return 0;
}