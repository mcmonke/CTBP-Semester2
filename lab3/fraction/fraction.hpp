#include <iostream>

class fraction{
    private:
        int num;
        int dem;
        static int proverka;

    public:
        static int getProverka();

        fraction();
        fraction(int n);
        fraction(int n, int d);
        fraction(const char* ch);
        fraction(double f);

        fraction& operator= (const fraction& fr2);
        fraction& operator= (const char* ch);
        fraction& operator= (double f);

        friend fraction operator+ (fraction f1, fraction f2);
        friend fraction operator+ (double f1, fraction f2);
        friend fraction operator+ (fraction f1, double f2);
        friend fraction operator+ (int f1, fraction f2);
        friend fraction operator+ (fraction f1, int f2);

        fraction& operator+= (fraction f2);
        fraction& operator+= (double f2);
        fraction& operator+= (int f2);

        friend std::ostream& operator << (std::ostream &out, const fraction& fr);
        friend std::istream& operator >> (std::istream &in, fraction& fr);
};