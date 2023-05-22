#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int m = 4, n = 3;
    int a[m][n];
    int randomRow[n];
    int randomColumn[m];
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            a[j][i] = rand() % 20;
        }
    }
    cout << "ARRAY";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "\t" << a[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 != 0)
            {
                int num;
                num = a[i][j];
                num *= 2;
                a[i][j] = num;
            }
        }
    }
    cout << endl
         << "First task: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << '\t' << a[i][j];
        }
        cout << endl;
    }
    /////////////////////// 2
    const int d = 3;
    double randomArr[d];
    for (int i = 0; i < d; i++)
    {
        randomArr[i] = rand() % 20;
    }
    cout << "\n 1D Array \n";
    for (int i = 0; i < d; i++)
    {
        cout << randomArr[i] << " ";
    }
    double min = randomArr[0];
    for (int i = 0; i < d; i++)
    {
        if (randomArr[i] > 0)
        {
            if (randomArr[i] < min)
            {
                min = randomArr[i];
            }
        }
    }
    cout << sqrt(min) << endl;
    cout << "\nDone 1D Array \n";
    for (int i = 0; i < d; i++)
    {
        cout << randomArr[i] << " ";
    }
    return 0;
}