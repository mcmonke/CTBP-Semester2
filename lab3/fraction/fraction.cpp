#include "fraction.hpp"
#include <iostream>

// Метод поиска наибольшего общего делителя (рекурсивный)
unsigned int findNod(unsigned int a, unsigned int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return findNod(a%b, b);
    return findNod(a, b%a);
}

int fraction::getProverka(){
    return proverka;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//КОНСТРУКТОРЫ//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

// Классический конструктор (создает число 1/1)
fraction::fraction(){
    num = 0;
    dem = 1;
}

// Конструктор (Создает число, используя введенные числитель и знаменатель)
fraction::fraction(int n, int d){
    if (d == 0){
        std::cout << "Ошибка! Деление на 0.\n";
        proverka = 0;
        return;
    }

    int nod = findNod(fabs(n), fabs(d));
    num = n/nod;
    dem = d/nod;
}

fraction::fraction(int n){
    num = n;
    dem = 1;
}

// Конструктор (Создает число, используя на входе строку, забирая из нее целую часть, числитель и знаменатель)
fraction::fraction(const char* ch){
    int num1, num2, num3 = 0;

    int sign;
    if (ch[0] == '-'){
        sign = -1;
    } else {
        sign = 1;
    }

    if (strchr(ch, ' ')) {
        sscanf(ch, "%d %d/%d", &num1, &num2, &num3);
        
        int FullNum = fabs(num1) * fabs(num3) + fabs(num2);

        if (num3 == 0){
            std::cout << "Ошибка! Деление на 0.\n";
            proverka = 0;
            return;
        }


        num = FullNum * sign;
        dem = num3;

    } else {
        if (strchr(ch, '/')) {
            sscanf(ch, "%d/%d", &num2, &num3);

            if(num3 == 0){
                std::cout << "Ошибка! Деление на 0.\n";
                proverka = 0;
                return;
            }

            num = num2;
            dem = num3;
        } else {
            sscanf(ch, "%d", &num2);
            num = num2;
            dem = 1;
        }
    }
    int nod = findNod(fabs(num), fabs(dem));
    num /= nod;
    dem /= nod;
}

// Конструктор (Создает объект фрактион из типа double)
fraction::fraction(double f){
    int sign = (f < 0) ? -1 : 1;
    double number = std::abs(f);

    // Выделяем целую часть
    int integerPart = static_cast<int>(number);
    
    // Вычисляем дробную часть
    double fractionalPart = number - integerPart;
    
    // Находим числитель и знаменатель дроби
    int numerator = static_cast<int>(fractionalPart * 1000000);
    int denominator = 1000000;

    int nod = findNod(numerator, denominator);
    numerator /= nod;
    denominator /= nod;

    int FullNum = fabs(integerPart) * fabs(denominator) + fabs(numerator);
    num = FullNum * sign;
    dem = denominator;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//ПЕРЕГРУЗКА ОПЕРАТОРОВ//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

fraction& fraction::operator= (const fraction& fr2){
    if (this != &fr2){ 
        this->num = fr2.num;
        this->dem = fr2.dem;
    }
    return *this;
}

fraction& fraction::operator= (const char* ch){
    fraction t(ch);
    this->num = t.num;
    this->dem = t.dem;
    
    return *this;
}

fraction& fraction::operator= (double f){
    fraction t(f);
    this->num = t.num;
    this->dem = t.dem;
    return *this;
}

fraction operator+ (fraction f1, fraction f2){
    return fraction(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

fraction operator+ (double f, fraction f2){
    fraction f1(f);
    return fraction(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

fraction operator+ (fraction f1, double f){
    fraction f2(f);
    return fraction(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

fraction operator+ (int f, fraction f2){
    fraction f1(static_cast<double>(f));
    return fraction(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

fraction operator+ (fraction f1, int f){
    fraction f2(static_cast<double>(f));
    return fraction(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

fraction& fraction::operator+= (fraction f2){
    fraction n(this->num * f2.dem + this->dem * f2.num, this->dem * f2.dem);
    this->num = n.num;
    this->dem = n.dem;
    return *this;
}

fraction& fraction::operator+= (double f2){
    fraction f(f2);
    fraction n(this->num * f.dem + this->dem * f.num, this->dem * f.dem);
    this->num = n.num;
    this->dem = n.dem;
    return *this;
}

fraction& fraction::operator+= (int f2){
    fraction f(static_cast<double>(f2));
    fraction n(this->num * f.dem + this->dem * f.num, this->dem * f.dem);

    this->num = n.num;
    this->dem = n.dem;
    return *this;
}

std::istream & operator >> (std::istream &in, fraction& fr){
    char tmp[50];
    in.getline(tmp, 50);
    fraction t(tmp);
    if(t.dem == 0){
        std::cout << "Ошибка! Деление на 0.\n";
    }else{
        fr = t;
    }
    return in;
}

std::ostream & operator << (std::ostream &out, const fraction& fr){
    if (fr.num == 0)
        out << 0;
    else if (fr.dem == 1)
        out << fr.num;
    else
    {
        if (abs(fr.num) < abs(fr.dem))
        {
            out << fr.num << "/" << fr.dem;
        }
        else
        {
            out << fr.num / fr.dem << " " << abs(fr.num % fr.dem) << "/" << fr.dem;
        }
    }
    return out;
}