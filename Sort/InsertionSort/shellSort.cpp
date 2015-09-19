#include <iostream>

#define N 10
using namespace std;

void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void shellSort(int a[], int n)
{
    int i, j, increment;
    int temp;
    for(increment = n/2; increment > 0; increment /= 2)
    {
        for(i = increment; i < n; i++)
        {
            temp = a[i];
            for(j = i; j >= increment && a[j - increment] > temp; j -= increment)
                a[j] = a[j - increment];
            a[j] = temp;
        }
    }
}

int main()
{
    int a[N] = {6, 5, 4, 0, 2, 1, 9, 8, 3, 7};
    printArray(a, N);
    shellSort(a, N);
    printArray(a, N);
    return 0;
}
