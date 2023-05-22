#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <string>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void exchange(T* arr, int i, int j) {
    swap(arr[i], arr[j]);
}

template<typename T>
void exchange_adjacent(T* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        swap(arr[i], arr[i+1]);
    }
}

int search(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int search(double* arr, int size, double value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int search(std::string* arr, int size, std::string value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

#endif
