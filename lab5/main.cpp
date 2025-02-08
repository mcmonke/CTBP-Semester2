#include <iostream>
#include <string>

#include "MyStl/MySet.hpp"
#include "MyStl/MyVector.hpp"

int main() {
    MyVector<char *> v((char *)"Hello!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    MyVector<char *> v1;
    v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;
    for (int i = 0; i < start_size; i++) v1.delete_element(0);
    std::cout << "Вектор v1: " << v1 << std::endl;

    MySet<char *> s((char *)"Yes"), s1, s2;
    s.add_element((char *)"Привет!");
    s.add_element((char *)"No");
    char *str = (char *)"Hello!";
    s.add_element(str);
    std::cout << "Множество s: " << s << std::endl;
    s1.add_element((char *)"Cat");
    s1.add_element((char *)"No");
    s1.add_element((char *)"Привет!");
    std::cout << "Множество s1: " << s1 << std::endl;
    s2 = s1 - s;
    std::cout << "Множество s2=s1-s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s - s1;
    std::cout << "Множество s2=s-s1: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = (s1 + s);
    std::cout << "Множество s2=s1+s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s1 * s;
    std::cout << "Множество s2=s1*s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    MySet<char *> s3;
    s3 = s2;
    std::cout << "Множество s3=s2: " << s3 << std::endl;
    if (s3 == s2)
        std::cout << "Множество s3=s2\n";
    else
        std::cout << "Множество s3!=s2\n";
    if (s3 == s1)
        std::cout << "Множество s3=s1\n";
    else
        std::cout << "Множество s3!=s1\n";
    if (s1 == s3)
        std::cout << "Множество s1=s3\n";
    else
        std::cout << "Множество s1!=s, se3\n";

    
    MySet<std::string> set1, set2;
    set1.add_element("1");
    set1.add_element("3");
    set1.add_element("5");

    set2.add_element("2");
    set2.add_element("4");

    std::cout << set1 << '\n';
    std::cout << set2 << '\n';

    set1 += set2;

    std::cout << set1 << '\n';

    set1 -= set2;

    std::cout << set1 << '\n';

    set1 += set2;

    set1 *= set2;

    std::cout << set1 << '\n';

    return 0;
}