#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

// A class for representing a one-dimensional array
class IntArray
{
    // Friend operator functions for output and input:
    friend ostream& operator <<(ostream& out, const IntArray& a);
    friend istream& operator >>(istream& in, IntArray& a);
private:
    int* pa = nullptr; // pointer to future array
    int  size = 0;     // current array size
public:
    // Nested class for creating an exception object
    class OutOfBounds
    {
        int index; // index out of range
    public:
        OutOfBounds(int i) : index(i) { } // constructor
        int getIndex() const { return index; } // getter for index
    };

    // Constructors:
    IntArray() { }
    IntArray(int n) { pa = new int[size = n]; }
    IntArray(IntArray& arr);

    ~IntArray(); // destructor
    void addElem(int elem); // function to add an element
    int& operator [](int index); // read and write access to elements

   // Overloaded operators:
    const IntArray& operator =(const IntArray& a);
    bool operator ==(const IntArray& a) const;

    int getSize() const { return size; } // returns the number of array elements
};

// Overloaded operator of writing to stream
ostream& operator <<(ostream& out, const IntArray& a)
{
    for (int i = 0; i < a.size; i++)
    {
        out << a.pa[i] << ' ';
    }
    return out;
}

// Overloaded operator of reading from stream
istream& operator >>(istream& in, IntArray& a)
{
    for (int i = 0; i < a.size; i++)
    {
        in >> a.pa[i];
    }
    return in;
}

// Copy constructor
IntArray::IntArray(IntArray& arr)
{
    size = arr.size;
    pa = new int[size];
    for (int i = 0; i < size; i++)
    {
        pa[i] = arr.pa[i];
    }
}

// Destructor
IntArray::~IntArray()
{
    if (pa != nullptr)
    {
        delete[] pa;
    }
}

// Adds an item. Allocates an array in a new place
void IntArray::addElem(int elem)
{
    int* temp = new int[size + 1];
    if (pa != nullptr)
    {
        for (int i = 0; i < size; i++)
        {
            temp[i] = pa[i];
        }
        delete[] pa;
    }
    pa = temp;
    pa[size] = elem;
    size++;
}

// Provides read and write access to elements
// Throws an OutOfBounds exception in case of a wrong index
int& IntArray:: operator [](int index)
{
    if (index < 0 || index >= size)
    {
        throw OutOfBounds(index);
    }
    return pa[index];
}

// Overloaded assignment operator
const IntArray& IntArray:: operator =(const IntArray& a)
{
    if (&a != this)
    {
        if (pa != nullptr)
        {
            delete[] pa;
        }
        size = a.size;
        pa = new int[size];
        for (int i = 0; i < size; i++)
        {
            pa[i] = a.pa[i];
        }
    }
    return *this;
}

// Overloaded array comparison operator
bool IntArray:: operator ==(const IntArray& a) const
{
    if (&a == this)
    {
        return true;
    }
    if (size != a.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (pa[i] != a.pa[i])
        {

            return false;
        }
    }
    return true;
}

// Global function for finding the minimum array item
// The function does not have direct access to the data and uses
// overloaded operators and member functions
int getMin(IntArray a) // call the copy constructor
{
    int min = a[0];
    for (int i = 1; i < a.getSize(); i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}

int main(void)
{
    setlocale(LC_ALL, "UKRAINIAN");
    IntArray a(2); // An array of two items
    cout << "Enter two array elements: ";
    cin >> a;
    cout << "Array items: " << a << endl;
    a.addElem(12);
    cout << "Adding element" << endl;
    cout << "Array items: " << a << endl;
    try
    {
        a[1] = 2;   // changed
        a[10] = 35; // wrong index
    }
    catch (IntArray::OutOfBounds& e)
    {
        cout << "Incorrect index: " << e.getIndex() << endl;
    }
    cout << "New items: " << a << endl;
    IntArray b; // created a new array
    b = a; // copying items
    if (a == b)
    {
        cout << "Arrays a and b are equal" << endl;
    }
    else
    {
        cout << "Arrays a and b are different";
    }
    cout << "Minimum element: " << getMin(a) << endl;
}