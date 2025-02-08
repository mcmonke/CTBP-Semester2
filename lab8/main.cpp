#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>

// Задание 1
std::string formSequence(const std::string& word1, const std::string& word2, const std::string& word3) {
    return word1.substr(0, 1) + " " + word2.substr(0, 1) + " " + word3.substr(0, 1);
}

// Задание 2
std::string swapFirstLastWords(const std::string& sentence) {
    std::istringstream iss(sentence);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }

    if (words.size() > 1) {
        std::swap(words.front(), words.back());
    }

    std::ostringstream oss;
    for (const auto& w : words) {
        oss << w << " ";
    }

    std::string result = oss.str();
    result.pop_back(); 
    return result;
}

// Задание 3
void processLine(std::string& line) {
    line = "e-mail: " + line;
}

// Задание 4 и 6
void printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}


// Задание 5
class Rectangle {
    double a;  // ширина
    double b;  // длина

public:
    Rectangle() : a(0), b(0) {}
    Rectangle(double width, double length) : a(width), b(length) {}

    double area() const {
        return a * b;
    }

    void print() const {
        std::cout << "Rectangle(" << a << ", " << b << ")" << std::endl;
    }

    bool operator<(const Rectangle& other) const {
        std::cout << "test2";
        return this->area() < other.area();
    }

    bool operator==(const Rectangle& other) const {
        return this->area() == other.area();
    }
};

bool compare1(const Rectangle& other, const Rectangle& another) {
    std::cout << "test";
    return another.area() < other.area();
};

void printRectangles(const std::vector<Rectangle>& rectangles) {
    for (const auto& rect : rectangles) {
        rect.print();
    }
}

// Задание 7
class Date {
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(1970) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void print() const {
        std::cout << (day < 10 ? "0" : "") << day << "."
                  << (month < 10 ? "0" : "") << month << "."
                  << year << std::endl;
    }

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator>(const Date& other) const {
        return other < *this;
    }

    bool isFuture() const {
        return *this > Date();
    }
};

void printDates(const std::list<Date>& dates) {
    for (const auto& date : dates) {
        date.print();
    }
}

// Задание 8
void printPlanets(const std::map<std::string, int>& planets) {
    for (const auto& planet : planets) {
        std::cout << planet.first << ": " << planet.second << std::endl;
    }
}

// Задание 9
void printMap(const std::map<std::string, int>& cities) {
    for (const auto& city : cities) {
        std::cout << city.first << ": " << city.second << " km" << std::endl;
    }
}

int main() {
    // Задание 1
    std::string word1, word2, word3;
    std::cout << "Enter three words: ";
    std::cin >> word1 >> word2 >> word3;
    std::string sequence = formSequence(word1, word2, word3);
    std::cout << "Resulting sequence: " << sequence << std::endl;

    std::cin.ignore();

    // Задание 2
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);
    std::string result = swapFirstLastWords(sentence);
    std::cout << "Modified sentence: " << result << std::endl;

    // Задание 3
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::string line;
    if (inputFile.is_open() && outputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            processLine(line);
            outputFile << line << std::endl;
        }
        inputFile.close();
        outputFile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    // Задание 4
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> vec(20);
    for (auto& val : vec) {
        val = std::rand() % 2;
    }
    printVector(vec);
    int trueCount = std::count(vec.begin(), vec.end(), 1);
    int falseCount = std::count(vec.begin(), vec.end(), 0);
    std::cout << "True count: " << trueCount << std::endl;
    std::cout << "False count: " << falseCount << std::endl;
    vec.erase(vec.begin(), vec.begin() + 10);
    printVector(vec);

    // Задание 5
    std::vector<Rectangle> rectangles = {
        Rectangle(1.2, 6.3), Rectangle(4.0, 0.7), Rectangle(7.2, 0.8),
        Rectangle(5.3, 3.0), Rectangle(4.9, 6.6), Rectangle(9.3, 0.2)
    };
    printRectangles(rectangles);
    auto maxIt = std::max_element(rectangles.begin(), rectangles.end(), compare1);
    if (maxIt != rectangles.end()) {
        std::cout << "Rectangle with largest area: ";
        maxIt->print();
    }

    // Задание 6
    std::list<int> lst;
    for (int i = 0; i < 20; ++i) {
        lst.push_back(std::rand() % 2);
    }
    printVector(std::vector<int>(lst.begin(), lst.end()));
    trueCount = std::count(lst.begin(), lst.end(), 1);
    falseCount = std::count(lst.begin(), lst.end(), 0);
    std::cout << "True count: " << trueCount << std::endl;
    std::cout << "False count: " << falseCount << std::endl;
    for (int i = 0; i < 10; ++i) {
        lst.pop_front();
    }
    printVector(std::vector<int>(lst.begin(), lst.end()));

    // Задание 7
    std::list<Date> dates = {
        Date(1, 2, 1963), Date(14, 7, 1995), Date(7, 12, 2088),
        Date(5, 3, 2030), Date(24, 9, 2013), Date(19, 9, 2020)
    };
    std::cout << "All dates:" << std::endl;
    printDates(dates);
    std::list<Date> futureDates;
    for (const auto& date : dates) {
        if (date.isFuture()) {
            futureDates.push_back(date);
        }
    }
    std::cout << "Future dates:" << std::endl;
    printDates(futureDates);

    // Задание 8
    std::map<std::string, int> planets = {
        {"Меркурий", 0}, {"Венера", 0}, {"Земля", 1}, {"Марс", 2},
        {"Юпитер", 69}, {"Сатурн", 62}, {"Уран", 27}, {"Нептун", 14}, {"Плутон", 100}
    };
    printPlanets(planets);
    auto maxItPlanet = std::max_element(planets.begin(), planets.end(),
                                  [](const auto& a, const auto& b) {
                                      return a.second < b.second;
                                  });
    std::cout << "Planet with most moons: " << maxItPlanet->first << " with " << maxItPlanet->second << " moons" << std::endl;

    // Задание 9
    std::map<std::string, int> cities = {
        {"Минск", 713}, {"Киев", 856}, {"Санкт-Петербург", 786},
        {"Астана", 2748}, {"Нижний Новгород", 421}, {"Владивосток", 9141}
    };
    printMap(cities);
    auto minIt = std::min_element(cities.begin(), cities.end(),
                                  [](const auto& a, const auto& b) {
                                      return a.second < b.second;
                                  });
    auto maxItCity = std::max_element(cities.begin(), cities.end(),
                                  [](const auto& a, const auto& b) {
                                      return a.second < b.second;
                                  });
    std::cout << "Closest city to Moscow: " << minIt->first << " (" << minIt->second << " km)" << std::endl;
    std::cout << "Farthest city from Moscow: " << maxItCity->first << " (" << maxItCity->second << " km)" << std::endl;

    return 0;
}