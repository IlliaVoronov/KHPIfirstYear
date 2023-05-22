// You need to develop a program that implements the sorting algorithms of 
// insertion, selection and bubble sort. 
// Also it is necessary to evaluate the effectiveness as a number of elements comparisons.
// First, create a sequence of 15-20 integer (real) elements. Then apply the sorting algorithms.
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int& comparisons) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int& comparisons) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(int arr[], int n, int& comparisons) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    cout << "input amount of integers: " << endl;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int random = rand() % 100;
        arr[i] = random;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    int comparisons = 0;
    insertionSort(arr, n, comparisons);
    cout << endl << "Insertion sort comparisons: " << comparisons << endl;
    printArray(arr, n);

    comparisons = 0;
    selectionSort(arr, n, comparisons);
    cout << "Selection sort comparisons: " << comparisons << endl;
    printArray(arr, n);

    comparisons = 0;
    bubbleSort(arr, n, comparisons);
    cout << "Bubble sort comparisons: " << comparisons << endl;
    printArray(arr, n);

    return 0;
}
