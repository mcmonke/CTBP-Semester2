#include <iostream>
#include <string>

enum class Color { red, green, orange };
enum class Fruit { apple, orange, pear };

template <typename T>
class Traits;

template <>
class Traits<Color> {
public:
    static std::string name(int index) {
        switch (index) {
            case static_cast<int>(Color::red):
                return "red";
            case static_cast<int>(Color::green):
                return "green";
            case static_cast<int>(Color::orange):
                return "orange";
            default:
                return "unknown";
        }
    }
};

template <>
class Traits<Fruit> {
public:
    static std::string name(int index) {
        switch (index) {
            case static_cast<int>(Fruit::apple):
                return "apple";
            case static_cast<int>(Fruit::orange):
                return "orange";
            case static_cast<int>(Fruit::pear):
                return "peach";
            default:
                return "unknown";
        }
    }
};

int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i != t; ++i) {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        std::cout << Traits<Color>::name(index1) << " ";
        std::cout << Traits<Fruit>::name(index2) << "\n";
    }
    return 0;
}