#include "virtual.h"
#include <cstring>
using namespace std;

// Конструктор по умолчанию для Товар
Goods::Goods() : name(nullptr) {
  cout << "Goods()\n";
}

// Параметрический конструктор для Товар
Goods::Goods(const char* n) {
  name = new char[strlen(n) + 1];
  strcpy(name, n);
  cout << "Goods(const char*)\n";
}

// Конструктор копирования для Товар
Goods::Goods(const Goods& other) {
  name = new char[strlen(other.name) + 1];
  strcpy(name, other.name);
}

// Оператор присваивания для Товар
Goods& Goods::operator=(const Goods& other) {
  if (this != &other) {
    delete[] name;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
  }
  return *this;
}

// Деструктор для Товар
Goods::~Goods() {
  delete[] name;
  cout << "~Goods()\n";
}

// Конструктор по умолчанию для Игрушка
Toy::Toy() : Goods(), color(nullptr) {
  cout << "Toy()\n";
}

// Параметрический конструктор для Игрушка
Toy::Toy(const char* n, const char* c) : Goods(n) {
  color = new char[strlen(c) + 1];
  strcpy(color, c);
  cout << "Toy(const char*, const char*)\n";
}

// Деструктор для Игрушка
Toy::~Toy() {
  delete[] color;
  cout << "~Toy()\n";
}

// Конструктор копирования для Игрушка
Toy::Toy(const Toy& other) : Goods(other) {
  color = new char[strlen(other.color) + 1];
  strcpy(color, other.color);
}

// Оператор присваивания для Игрушка
Toy& Toy::operator=(const Toy& other) {
  if (this != &other) {
    Goods::operator=(other);
    delete[] color;
    color = new char[strlen(other.color) + 1];
    strcpy(color, other.color);
  }
  return *this;
}


// Функция show для Игрушка
void Toy::show() {
  cout << "Name: " << name << endl;
  cout << "Color: " << color << endl;
}

// Конструктор по умолчанию для Продукт
Product::Product() : Goods(), origin(nullptr), shelf_life(0) {
  cout << "Product() default\n";
}

// Параметрический конструктор для Продукт
Product::Product(const char* n, const char* m, int s) : Goods(n), shelf_life(s) {
  origin = new char[strlen(m) + 1];
  strcpy(origin, m);
  cout << "Product(const char*, const char*, int)\n";
}

// Деструктор для Продукт
Product::~Product() {
  delete[] origin;
  cout << "~Product()\n";
}

// Конструктор копирования для Продукт
Product::Product(const Product& other) : Goods(other) {
  origin = new char[strlen(other.origin) + 1];
  strcpy(origin, other.origin);
  shelf_life = other.shelf_life;
}

// Оператор присваивания для Продукт
Product& Product::operator=(const Product& other) {
  if (this != &other) {
    Goods::operator=(other);
    delete[] origin;
    origin = new char[strlen(other.origin) + 1];
    strcpy(origin, other.origin);
    shelf_life = other.shelf_life;
  }
  return *this;
}

// Функция show для Продукт
void Product::show() {
  cout << "Name: " << name << endl;
  cout << "Origin: " << origin << endl;
  cout << "Shelf life: " << shelf_life << " days\n";
}

// Конструктор по умолчанию для Молочный продукт
Dairy_Product::Dairy_Product() : Product(), fat_content(0) {
  cout << "Dairy_Product()\n";
}

// Параметрический конструктор для Молочный продукт
Dairy_Product::Dairy_Product(const char* n, const char* m, int s, double f) : Product(n, m, s), fat_content(f) {
  cout << "Dairy_Product(const char*, const char*, int, double)\n";
}

// Деструктор для Молочный продукт
Dairy_Product::~Dairy_Product() {
  cout << "~Dairy_Product()\n";
}

// Конструктор копирования для Молочный продукт
Dairy_Product::Dairy_Product(const Dairy_Product& other) : Product(other) {
  fat_content = other.fat_content;
}

// Оператор присваивания для Молочный продукт
Dairy_Product& Dairy_Product::operator=(const Dairy_Product& other) {
  if (this != &other) {
    Product::operator=(other);
    fat_content = other.fat_content;
  }
  return *this;
}

// Функция show для Молочный продукт
void Dairy_Product::show() {
  cout << "Name of Product: " << name << endl;
  cout << "Origin: " << origin << endl;
  cout << "Shelf life: " << shelf_life << " days\n";
  cout << "Fat content: " << fat_content << "%\n";
}