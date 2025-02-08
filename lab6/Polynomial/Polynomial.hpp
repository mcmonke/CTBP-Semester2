#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstring>
#include <iostream>
#include <sstream>

#include "../MyVector/MyVector.hpp"

class Term {
   private:
    int _coef;  // число
    int _exp;   // степень

   public:
    Term(int coef = 0, int exp = 0) : _coef(coef), _exp(exp){};
    int getInt() const { return _coef; }
    int getExp() const { return _exp; }
    Term& operator=(const Term& tr);
    friend Term operator+(const Term& t1, const Term& t2);
    friend std::ostream& operator<<(std::ostream& out, const Term& fr);
    friend std::istream& operator>>(std::istream& in, Term& fr);

    friend class Polynomial;
};

class Polynomial {
   private:
    int _degree;
    MyVector<Term> _poly;
    bool _order = false;

   public:
    Polynomial() = default;
    Polynomial(int coef, int exp);
    Polynomial(const Polynomial& pl);

    Polynomial& operator+=(const Term& tr);
    Polynomial& operator+=(const Polynomial& pl);

    friend Polynomial operator+(const Polynomial& pl1, const Term& tr);
    friend Polynomial operator+(const Polynomial& pl1, const Polynomial& pl2);

    Polynomial& operator*=(const Term& tr);
    Polynomial& operator*=(const Polynomial& tr);
    friend Polynomial operator*(const Polynomial& pl1, const Term& pl2);
    friend Polynomial operator*(const Polynomial& pl1, const Polynomial& pl2);

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& pl);
    friend std::istream& operator>>(std::istream& in, Polynomial& pl);
};

#endif