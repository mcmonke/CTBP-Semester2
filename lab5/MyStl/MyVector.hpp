#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>

const int start_size = 6;

template <class T> class MyVector {

    protected:

        int max_size;
        int size;
        T* pdata;

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
            max_size = v.max_size;
            pdata = new T[start_size];
            for (int i = 0; i < v.getSize(); ++i) {
                add_element(v.pdata[i]);
            }
        };

        ~MyVector() { 
            delete[] pdata; 
        };

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

        T &operator[](int i) const {
            if (i >= size) {
                std::cerr << "Выход за пределы границ вектора\n";
                return pdata[size];
            } else {
                return pdata[i];
            }
        };

        int partition(T *arr, int low, int high) {
            T pivot = arr[high];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }

            std::swap(arr[i + 1], arr[high]);
            return i + 1;
        };

        void quickSort(T *arr, int low, int high) {
            if (low < high) {
                int pi = partition(arr, low, high);

                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        };

        void sort() { 
            quickSort(pdata, 0, size - 1); 
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
            this->max_size = v.getMaxSize();
            this->size = v.getSize();

            T *newArr = new T[max_size];

            for (int i = 0; i < size; ++i) {
                newArr[i] = v[i];
            }
            this->delete_memory();
            
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

//  specializations:

template <>
inline void MyVector<char *>::add_element(char *el) {
    //max_size = start_size;
    pdata[size] = new char[strlen(el) + 1];
    strcpy(pdata[size], el);
    size++;
    resize(max_size * 2);
};

template <>
inline MyVector<char *>::MyVector(char *el) {
    size = 1;
    max_size = start_size;
    pdata = new char *[max_size];
    if (!el) {
        pdata[0] = new char[1];
    } else {
        pdata[0] = new char[strlen(el) + 1];
        strcpy(pdata[0], el);
    }
};

template <>
inline int MyVector<char *>::partition(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
};

template <>
inline MyVector<char *>::MyVector(const MyVector &v) {
    max_size = v.max_size;
    size = 0;
    pdata = new char *[max_size];
    for (int i = 0; i < v.getSize(); ++i) {
        add_element(v.pdata[i]);
    }
};

template <>
inline MyVector<char *>::~MyVector() {
    for (int i = 0; i < size; i++) {
        delete[] pdata[i];
    }
    delete[] pdata;
};

template <>
inline void MyVector<char *>::delete_memory() {
    for (int i = 0; i < size; i++) {
        delete[] pdata[i];
    }
    delete[] pdata;
};

template <>
inline bool MyVector<char *>::delete_element(int i) {
    if (i < size) {
        delete[] pdata[i];
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

template <>
inline int MyVector<char *>::find(char *el) const {
    for (int i = 0; i < size; ++i) {
        if (strcmp(pdata[i], el) == 0) {
            return i;
        }
    }
    return -1;
};

template <>
inline int MyVector<char *>::binarySearch(char **arr, int l, int r, char *x) const {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (strcmp(arr[m], x) == 0) return m;

        if (strcmp(arr[m], x) < 0)
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;
};

template <>
inline MyVector<char *> &MyVector<char *>::operator=(const MyVector &v) {
    this->delete_memory();
    this->max_size = v.max_size;
    this->size = v.size;

    char **newArr = new char *[max_size];

    for (int i = 0; i < size; ++i) {
        newArr[i] = new char[strlen(v[i]) + 1];
        strcpy(newArr[i], v[i]);
    }

    this->pdata = newArr;

    return *this;
};

#endif