#include <iostream>
using namespace std;

int main(void)
{
    int n = 5;
    cout << &n << endl;
    int *ptr = &n;
    cout << ptr << endl;
    cout << *ptr << endl;
    *ptr = 10;
    cout << *ptr << endl;
    cout << n << endl;

    return 0;
}