#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>

const int start_size = 5;

template <class T> class MyVector {

    protected:

        int max_size;
        int size;
        T* pdata;

        void resize(int newSize) {
            if (size >= max_size || size <= max_size / 2) {
                T *newArr = new T[newSize];
                for (int i = 0; i < size; ++i) {
                    newArr[i] = pdata[i];
                }
                delete[] pdata;
                pdata = newArr;
                max_size = newSize;
            }
        };

        void insertionSort(T *arr, int n, bool order) {
            int i, j;
            T key;
            for (i = 1; i < n; i++) {
                key = arr[i];
                j = i - 1;

                while (j >= 0 && ((arr[j].getExp() > key.getExp()) && order) ||
                    ((arr[j].getExp() < key.getExp()) && !order)) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            };
        };

    public:

        MyVector() {
            max_size = start_size;
            pdata = new T[max_size];
            size = 0;
        };

        MyVector(const T el) {
            max_size = start_size;
            pdata = new T[max_size];
            if (!el) {
                size = 0;
            } else {
                pdata[0] = el;
                size = 1;
            }
        };

        MyVector(const MyVector &v) {
            max_size = start_size;
            pdata = new T[start_size];
            for (int i = 0; i < v.getSize(); ++i) {
                add_element(v.pdata[i]);
            }
        };

        ~MyVector() { 
            delete[] pdata; 
        };

        void add_element(const T el) {
            pdata[size] = el;
            size++;
            resize(max_size * 2);
        };

        void delete_memory() {
            delete[] pdata;
        };

        bool delete_element(int i) {
            if (i < size) {
                for (int j = i + 1; j < size; ++j) {
                    pdata[j - 1] = pdata[j];
                }
                --size;
                resize(max_size / 2);
            } else {
                std::cerr << "Выход за пределы границ вектора\n";
            }
            return false;
        };

        T &operator[](int i) const { return pdata[i]; }

        void sort(bool order) { 
            insertionSort(pdata, size, order);
        };


        int getSize() const { 
            return size;
        };

        int getMaxSize() const { 
            return max_size; 
        };

        int find(const T el) const {
            for (int i = 0; i < size; ++i) {
                if (pdata[i] == el) {
                    return i;
                }
            }
            return -1;
        };

        int binarySearch(T *arr, int l, int r, T x) const {
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (arr[m] == x) {
                    return m;
                }
                if (arr[m] < x)
                    l = m + 1;
                else
                    r = m - 1;
            }
            return -1;
        };

        MyVector &operator=(const MyVector &v) {
            this->delete_memory();
            this->max_size = v.getMaxSize();
            this->size = v.getSize();

            T *newArr = new T[max_size];

            for (int i = 0; i < size; ++i) {
                newArr[i] = v[i];
            }
            
            this->pdata = newArr;

            return *this;
        };

        friend std::ostream &operator<<(std::ostream &out, const MyVector &v) {
            for (int i = 0; i < v.getSize(); i++) {
                out << v.pdata[i] << ' ';
            }
            return out;
        };
};
#endif