#include <iostream>

class A_based {
public:
    A_based() {
        std::cout << "Конструктор A_based\n";
    }
    virtual ~A_based() {
        std::cout << "Деструктор A_based\n";
    }

    virtual void function() = 0;
};

class B_derived : virtual public A_based {
public:
    B_derived() {
        std::cout << "Конструктор B_derived\n";
    }
    ~B_derived() override {
        std::cout << "Деструктор B_derived\n";
    }

    void function() override {
        std::cout << "Функция из B_derived\n";
    }
};

class C_derived : virtual public A_based {
public:
    C_derived() {
        std::cout << "Конструктор C_derived\n";
    }
    ~C_derived() override {
        std::cout << "Деструктор C_derived\n";
    }

    void function() override {
        std::cout << "Функция из C_derived\n";
    }
};

class D_derived : public B_derived, public C_derived {
public:
    D_derived() {
        std::cout << "Конструктор D_derived\n";
    }
    ~D_derived() override {
        std::cout << "Деструктор D_derived\n";
    }

    void function() override {
        B_derived::function();
        C_derived::function();
    }
};

int main() {
    D_derived d;
    d.function();
    return 0;
}