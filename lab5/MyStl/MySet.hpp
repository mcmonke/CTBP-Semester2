#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include "MyVector.hpp"

template <class T> class MySet : public MyVector<T> {

    public:

        MySet(T el) : MyVector<T>(el){};
        MySet() : MyVector<T>(){};
        
        int q_find(T &el) const {
            return this->binarySearch(this->pdata, 0, this->size - 1, el);
        }

        void add_element(T el) {
            if (!is_element(el)) {
                this->MyVector<T>::add_element(el);
                this->sort();
            }
        }

        void delete_element(T el) {
            int index = q_find(el);
            if (index != (-1)){
                MyVector<T>::delete_element(index);
            }
        }

        bool is_element(T el) const { 
            return q_find(el) != -1; 
        }

        bool operator==(MySet &s) {
            bool res = true;
            for (int i = 0; i < s.getSize(); ++i) {
                if (this->is_element(s[i]) == -1) {
                    res = false;
                    break;
                }
            }
            return res;
        }

        MySet &operator+=(const MySet &s) {
            for (int i = 0; i < s.getSize(); ++i) {
                if (!this->is_element(s[i])) this->add_element(s[i]);
            }
            return *this;
        }

        MySet &operator-=(const MySet &s) {
            for (int i = 0; i < s.getSize(); ++i) {
                if (this->is_element(s[i])) {
                    this->delete_element(s[i]);
                }
            }
            return *this;
        }

        MySet &operator*=(const MySet &s) {
            for (int i = 0; i < s.getSize(); ++i) {
                if (this->is_element(s[i])==0) {
                    this->delete_element(s[i]);
                }
            }
            for (int i = 0; i < this->getSize(); ++i) {
                if (s.is_element(this->pdata[i])==0) {
                    this->delete_element(this->pdata[i]);
                }
            }
            
            return *this;
        }

        friend MySet operator+(const MySet &set1, const MySet &set2) {
            MySet<T> tmp;
            tmp = set1;
            tmp += set2;
            return tmp;
        }

        friend MySet operator-(const MySet &set1, const MySet &set2) {
            MySet<T> tmp;
            tmp = set1;
            tmp -= set2;
            return tmp;
        }

        friend MySet operator*(const MySet &set1, const MySet &set2) {
            MySet<T> tmp;
            tmp = set1;
            tmp *= set2;
            return tmp;
        }
};

#endif