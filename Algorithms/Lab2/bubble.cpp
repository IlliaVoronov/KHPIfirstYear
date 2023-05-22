#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int l, int r, int x);

void printArray(int arr[], int size);

int main()
{
	int N;
	cout << "Input size of first array: " << endl;
	cin >> N;
	int arrN[N];
	for (int i = 0; i < N; i++) {
		cout << "Input " << i + 1 << " element of array: " << endl;
		cin >> arrN[i];
		
	}

	cout << "First array -> ";
	printArray(arrN, N);
	bubbleSort(arrN, N);
	cout << "Sorted first array: \n";
	printArray(arrN, N);
	
	// Second array 
	int M;
	cout << "Input size of second array: " << endl;
	cin >> M;
	int arrM[M];
	for (int i = 0; i < M; i++) {
		cout << "Input " << i + 1 << " element of array: " << endl;
		cin >> arrM[i];
	}
	cout << "Second array -> ";
	printArray(arrM, M);

	for (int i = 0; i < M; i++) {
		int result = binarySearch(arrN, 0, M, arrM[i]);
		if (result >= 0) {
		cout << "Your number " << arrM[i] << " is placed by index: " << result << endl;
		}
		else {
		cout << "There is no " << arrM[i] << " in the arrey :(" << endl;
		}
    }

	return 0;
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i <= n; i++)

		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j + 1]);
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
