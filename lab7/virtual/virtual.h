#include "../vectorx/myvector.h"
#include <iostream>

class Goods {
public:
  Goods();                // Конструктор по умолчанию
  Goods(const char* n);   // Параметрический конструктор
  virtual ~Goods();
  virtual void show() = 0;

protected:
  Goods(const Goods& other);  // Конструктор копирования
  Goods& operator=(const Goods& other);  // Оператор присваивания
  char* name;
};

// Класс Игрушка, наследуемый от Товар
class Toy : public Goods {
public:
  Toy(); // Конструктор по умолчанию
  Toy(const char* n, const char* c);
  // Конструктор копирования
  Toy(const Toy& t);
  Toy& operator=(const Toy& t);
  virtual ~Toy();
  virtual void show();

protected:
  // Цвет игрушки
  char* color;
};

// Класс Продукт, наследуемый от Товар
class Product : public Goods {
public:
  Product(); // Конструктор по умолчанию
  Product(const char* n, const char* m, int s); // n, m, s
  Product(const Product& p);
  Product& operator=(const Product& p);
  virtual ~Product();
  virtual void show();

protected:
  // Место происхождения продукта
  char* origin;
  // Срок годности
  int shelf_life;
};

// Класс Молочный продукт, наследуемый от Продукт
class Dairy_Product : public Product {
public:
  Dairy_Product(); // Конструктор по умолчанию
  Dairy_Product(const char* n, const char* m, int s, double f); // s = срок годности, f = содержание жира
  Dairy_Product(const Dairy_Product& d);
  Dairy_Product& operator=(const Dairy_Product& d);
  virtual ~Dairy_Product();
  virtual void show();

protected:
  // Содержание жира
  double fat_content;
};