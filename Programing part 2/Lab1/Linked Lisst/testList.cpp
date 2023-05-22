#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

const int n = 5; // define constant for number of columns

int main() {

    // Step 1: Opening file for reading
    ifstream input_file("input.txt");
    if (!input_file) {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    // Step 2: Reading integer values until the end of file and storing them in the linked list
    list<int> values_list;
    int value;
    while (input_file >> value) {
        values_list.push_back(value);
    }

    // Step 3: Calculation of row count for the two-dimensional array
    int row_count = ceil((double) values_list.size() / n);

    // Step 4: Creation of two-dimensional array in free store
    int **arr = new int*[row_count];
    for (int i = 0; i < row_count; i++) {
        arr[i] = new int[n];
    }

    // Step 5: Filling of two-dimensional array row by row, missing elements of the last row should be set to zeroes
    int count = 0;
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < n; j++) {
            if (count < values_list.size()) {
                arr[i][j] = values_list.front();
                values_list.pop_front();
                count++;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }

    // Step 6: Removing elements of linked list from free store
    values_list.clear();

    // Step 7: Storing results in a new file
    ofstream output_file("output.txt");
    if (!output_file) {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < n; j++) {
            output_file << arr[i][j] << " ";
        }
        output_file << endl;
    }

    // Step 8: Removing both arrays using delete operators
    for (int i = 0; i < row_count; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}







// #include <iostream>
// #include <fstream>

// using namespace std;

// int const n = 5;

// struct Link
// {
//     int data;
//     Link *next;
// };



// int main(void)
// {

//     return 0;
// }