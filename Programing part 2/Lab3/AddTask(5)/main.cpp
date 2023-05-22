#include <iostream>
#include "array_utils.h"
using namespace std;

int main() {
    cout << "---------------------Example usage with integers---------------------" << endl;
    int int_arr[] = {1, 2, 3, 4, 5};
    int int_size = sizeof(int_arr) / sizeof(int);
    exchange(int_arr, 1, 3);
    cout << "Switched 1 and 3: " << endl;
    for (int i = 0; i < int_size; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;
    cout << "Index of value 3: " << search(int_arr, int_size, 3) << endl;
    exchange_adjacent(int_arr, int_size);
    for (int i = 0; i < int_size; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;


    cout << "---------------------Example usage with strings---------------------" << endl;
    string string_arr[] = {"apple", "banana", "cherry", "samsung", "elderberry"};
    int string_size = sizeof(string_arr) / sizeof(string);
    exchange(string_arr, 2, 4);
    cout << "Switched 1 and 3: " << endl;
    for (int i = 0; i < string_size; i++) {
        cout << string_arr[i] << " ";
    }
    cout << endl;
    cout << "Index of value \"banana\": " << search(string_arr, string_size, "banana") << endl;
    exchange_adjacent(string_arr, string_size);
    for (int i = 0; i < string_size; i++) {
        cout << string_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
