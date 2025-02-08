#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <string.h>
#include <iostream>

template <typename T>
class MyVector {
   protected:
    int max_size;
    int size;
    T *pdata;
    void resize();

   public:
    MyVector(): max_size(1), size(0){
        pdata = new T[1];
    };
    MyVector(T el, int max_size = 1);
    MyVector(const MyVector<T> &v);
    ~MyVector();
    void add_element(T el);
    bool delete_element(int i);
    T &operator[](int i)const ;
    void sort();
    int get_size() const { return size; }
    int get_max_size() const { return max_size; }
    int find(T el);
    MyVector<T> &operator=(const MyVector<T> &v);
    template <typename F>
    friend std::ostream &operator<<(std::ostream &out, const MyVector<F> &v);
};
    
template <typename T>
MyVector<T>::MyVector(T el, int max_size) : max_size(max_size), size(0) {
    pdata = new T[max_size];
    if (el != T()) {
        pdata[size] = el;
        size++; 
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &v) : max_size(v.max_size), size(v.size) {
    pdata = new T[max_size];
    for (int i = 0; i < size; ++i) {
        pdata[i] = v.pdata[i];
    }
}

template <typename T>
void MyVector<T>::resize() {
    int new_max_size = 0;
    if (size >= max_size) {
        new_max_size = max_size * 2;
    } else {
        new_max_size = max_size / 2;
    }
    if (new_max_size < 1) {
        new_max_size = 1;
    }
    T *temp = new T[new_max_size];
    for (int i = 0; i < size; ++i) {
        temp[i] = pdata[i];
    }
    delete[] pdata;
    pdata = temp;
    max_size = new_max_size;
}

template <typename T>
void MyVector<T>::add_element(T el) {
    if (size >= max_size) {
        resize();
    }
    pdata[size] = el;
    size++;
}

template <typename T>
bool MyVector<T>::delete_element(int i) {
    if (i < 0 || i >= size) {
        return false;
    }
    for (int j = i; j < size - 1; ++j) {
        pdata[j] = pdata[j + 1];
    }
    size--;

    if (size < max_size / 4 && max_size > 1) {
        resize();
    }

    return true;
}

template <typename T>
int MyVector<T>::find(T el) {
    for (int i = 0; i < size; ++i) {
        if (pdata[i] == el) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void MyVector<T>::sort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (pdata[j] > pdata[j + 1]) {
                T temp = pdata[j];
                pdata[j] = pdata[j + 1];
                pdata[j + 1] = temp;
            }
        }
    }
}

template <typename T>
T &MyVector<T>::operator[](int i)const  {
    return pdata[i];
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v) {
    if (this != &v) {
        delete[] pdata;
        max_size = v.max_size;
        size = v.size;
        pdata = new T[max_size];
        for (int i = 0; i < size; ++i) {
            pdata[i] = v.pdata[i];
        }
    }
    return *this;
}

template <typename F>
std::ostream &operator<<(std::ostream &out, const MyVector<F> &v) {
    out << "[ ";
    for (int i = 0; i < v.size; ++i) {
        out << v.pdata[i];
        if (i < v.size - 1) {
            out << ", ";
        }
    }
    out << " ]";
    return out;
}


#endif  // INHERITANCE_MYVECTOR_H