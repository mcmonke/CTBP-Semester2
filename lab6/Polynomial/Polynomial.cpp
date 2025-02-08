#include "Polynomial.hpp"
#include <cstring>
#include <cctype>
#include <cstdio>
#include <utility>
#include <algorithm>

void removeSpaces(char* str) {
    int length = strlen(str);
    char* end = std::remove_if(str, str + length, [](unsigned char c) { return std::isspace(c); });
    *end = '\0';
}

std::pair<int, int> parceStrToTerm(char* str) {
    bool hasX = false, hasPower = false;
    int posX = -1, posPower = -1;

    // Определяем позиции 'x' и '^'
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == 'x') {
            hasX = true;
            posX = i;
        }
        if (str[i] == '^') {
            hasPower = true;
            posPower = i;
        }
    }

    int coef = 1, power = 0;

    if (hasX) {
        if (posX > 0 && isdigit(str[posX - 1])) {
            sscanf(str, "%d", &coef);
        } else if (posX == 0 || (posX > 0 && str[posX - 1] == '-')) {
            coef = (posX == 0) ? 1 : -1;
        }

        if (hasPower) {
            sscanf(str + posPower + 1, "%d", &power);
        } else {
            power = 1;
        }
    } else {
        sscanf(str, "%d", &coef);
    }

    return {coef, power};
}

Term operator+(const Term& t1, const Term& t2) {
    if (t1.getExp() != t2.getExp()) {
        std::cerr << "Error: Нельзя складывать члены разных степеней" << std::endl;
        exit(0);
    }

    Term newTerm(t1.getInt() + t2.getInt(), t1.getExp());
    return newTerm;
}

Term& Term::operator=(const Term& tr) {
    this->_coef = tr.getInt();
    this->_exp = tr.getExp();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Term& tr) {
    int cntr = 0;
    if (tr.getInt() == -1) {
        out << "- ";
        cntr += 1;
    }
    else if (tr.getInt() != 1) {
        if (tr.getInt() < 0) {
            out << "- " << -tr.getInt();
            cntr += 1;
        }
        else{
            if (cntr == 0 && tr.getInt() == 0){
                
            } else {
                out << tr.getInt();
                cntr += 1;
            }
        }
    }

    if (tr.getExp() == 0) {
        if (tr.getInt() == 1){
            return out << '1';
        } else if (tr.getInt() == -1){
            return out << "1";
        } else {
            return out;
        }
    } else if (tr.getExp() == 1 && (tr.getInt() !=0)) {
        out << 'x';
    } else if ((tr.getInt() !=0)){
        out << "x^" << tr.getExp();
    }
    return out;
}

std::istream& operator>>(std::istream& in, Term& fr) {
    char str[50];
    std::cin.getline(str, 50);
    removeSpaces(str);
    auto [coef, power] = parceStrToTerm(str);
    if (coef != 0) {
        fr._coef = coef;
        fr._exp = power;
    } else {
        fr._coef = 0;
        fr._exp = 0;
    }

    return in;
}

Polynomial::Polynomial(int coef, int exp) {
    Term tr(coef, exp);
    _poly.add_element(tr);
}

Polynomial::Polynomial(const Polynomial& pl) {
    _poly = pl._poly;
}

Polynomial& Polynomial::operator+=(const Term& tr) {
    if (tr.getExp() == 0 && tr.getInt() == 0) return *this;
    for (int i = 0; i < _poly.getSize(); ++i) {
        if (_poly[i].getExp() == tr.getExp()) {
            _poly[i] = _poly[i] + tr;
            return *this;
        }
    }

    _poly.add_element(tr);
    _poly.sort(_order);
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& pl) {
    for (int i = 0; i < pl._poly.getSize(); ++i) {
        *this += pl._poly[i];
    }
    return *this;
}

Polynomial operator+(const Polynomial& pl1, const Term& tr) {
    Polynomial temp(pl1);
    temp += tr;
    return temp;
}

Polynomial operator+(const Polynomial& pl1, const Polynomial& pl2) {
    Polynomial temp(pl1);
    for (int i = 0; i < pl2._poly.getSize(); ++i) {
        temp += pl2._poly[i];
    }
    return temp;
}

Polynomial& Polynomial::operator*=(const Term& tr) {
    for (int i = 0; i < _poly.getSize(); ++i) {
        _poly[i]._coef *= tr.getInt();
        _poly[i]._exp += tr.getExp();
    }
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& pl) {
    Polynomial result;
    for (int i = 0; i < _poly.getSize(); ++i) {
        for (int j = 0; j < pl._poly.getSize(); ++j) {
            Term newTerm(_poly[i].getInt() * pl._poly[j].getInt(),
                         _poly[i].getExp() + pl._poly[j].getExp());
            result += newTerm;
        }
    }
    *this = result;
    return *this;
}

Polynomial operator*(const Polynomial& pl1, const Term& tr) {
    Polynomial temp(pl1);
    temp *= tr;
    return temp;
}

Polynomial operator*(const Polynomial& pl1, const Polynomial& pl2) {
    Polynomial temp(pl1);
    temp *= pl2;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& pl) {
    if (pl._poly.getSize() == 0)
        return out << 0;
    else {
        for (int i = 0; i < pl._poly.getSize() - 1; i++) {
            out << pl._poly[i];
            if (pl._poly[i + 1].getInt() > 0)
                out << " + ";
            else if (pl._poly[i + 1].getInt() == 0)
                out << " + ";
            else if (pl._poly[i + 1].getInt() < 0)
                out << ' ';
        }
        out << pl._poly[pl._poly.getSize() - 1];
        return out;
    }
}

std::istream& operator>>(std::istream& in, Polynomial& pl) {
    char str[1000];
    in.getline(str, 1000);
    removeSpaces(str);

    MyVector<char> simbs;
    int startpos = 0;

    if (str[0] != '-') {
        startpos = 1;
        simbs.add_element('+');
    }
 
    for (int i = startpos; i < strlen(str); ++i) {
        if (str[i] == '-' || str[i] == '+') {
            simbs.add_element(str[i]);
        }
    }

    const char* delim = "+-";
    char* token = strtok(str, delim);
    int simbIndex = 0;

    while (token != NULL) {
        char tmpStr[1000];
        tmpStr[0] = simbs[simbIndex];
        tmpStr[1] = '\0';

        strcat(tmpStr, token);
        auto [coef, power] = parceStrToTerm(tmpStr);
        if (coef == 0) power = 0;
        Term tmp(coef, power);
 
        token = strtok(NULL, delim);
        simbIndex += 1;
        pl += tmp;
    }

    return in;
}