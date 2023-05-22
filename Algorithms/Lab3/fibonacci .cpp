#include <bits/stdc++.h>
using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


// find minimum of two elements
int min(int x, int y) { return (x <= y) ? x : y; }

int fibMonaccianSearch(int arr[], int x, int n)
{
	/* Initialize fibonacci numbers */
	int fibMMm2 = 0; // (m-2)'th Fibonacci No.
	int fibMMm1 = 1; // (m-1)'th Fibonacci No.
	int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

	/* fibM is going to store the smallest Fibonacci
	Number greater than or equal to n */
	while (fibM < n) {
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Marks the eliminated range from front
	int offset = -1;

	/* while there are elements to be inspected. Note that
	we compare arr[fibMm2] with x. When fibM becomes 1,
	fibMm2 becomes 0 */
	while (fibM > 1) {
		// Check if fibMm2 is a valid location
		int i = min(offset + fibMMm2, n - 1);

		/* If x is greater than the value at index fibMm2,
		cut the subarray array from offset to i */
		if (arr[i] < x) {
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		/* If x is greater than the value at index fibMm2,
		cut the subarray after i+1 */
		else if (arr[i] > x) {
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}
		else
			return i;
	}

	/* comparing the last element with x */
	if (fibMMm1 && arr[offset + 1] == x)
		return offset + 1;

	/*element not found. return -1 */
	return -1;
}


int main()
{
    int n;
    cout << "Input size of Array ";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cout << endl << "Input " << i + 1 << " element of array: ";
		cin >> arr[i];
		
	}

    bubbleSort(arr, n);

	cout << endl << "Sorted Array -> ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
	int x;
    cout << endl << " What number you want to find?: ";
    cin >> x;

	int ind = fibMonaccianSearch(arr, x, n);
    if(ind>=0)
	    cout << "Found at index: " << ind;
    else
	    cout << x << " isn't present in the array";
    return 0;
}

 
