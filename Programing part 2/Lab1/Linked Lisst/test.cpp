#include<iostream>
#include <fstream>

using namespace std;

// A link:
struct Link
{
    int data;
    Link *next;
};

// The function reads numbers from the specified file
// and returns a pointer to the initial item of the array.
// The array is created inside the function, its items
// are located in the free store
// The parameter count after the function completes contains the length of the array
int *readFromFile(const char *fileName, int &count)
{
    // Prepare the linked list to work and create a file stream:
    Link *first = 0;
    Link *last = 0;
    Link *link;
    ifstream in(fileName);
    int d;
    count = 0;      // counter of numbers read from the file
    while (in >> d) // read to the end of the file
    {
        count++;
        // Create a new list item:
        link = new Link;
        link->data = d;
        link->next = 0;
        if (last == 0)
        {
            first = link;
        }
        else
        {
            last->next = link;
        }
        last = link;
    }
    // Create and fill an array of numbers:
    int *arr = new int[count];
    link = first;
    for (int i = 0; i < count; i++)
    {
        arr[i] = link->data;
        link = link->next;
    }
    // Deleting elements of the linked list from the free store:
    while (first)
    {
        link = first;
        first = first->next;
        delete link;
    }
    return arr;
}

// Writes the elements of the array arr of length count
// to the specified text file
void outToFile(const char *filename, int *arr, int count)
{
    ofstream out(filename);
    for (int i = count - 1; i >= 0; i--)
    {
        out << arr[i] << " ";
    }
}

int main()
{
    int count = 0;
    int *arr = readFromFile("InputFile.txt", count);
    outToFile("results.txt", arr, count);
    delete [] arr;
    return 0;
}