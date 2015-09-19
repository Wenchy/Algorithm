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

void straightInsertionSort(int a[], int n)
{
    int i, j;
    int temp;
    for(i = 1; i < n; i++)
    {
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
    }
}

int main()
{
    int a[N] = {6, 5, 4, 0, 2, 1, 9, 8, 3, 7};
    printArray(a, N);
    straightInsertionSort(a, N);
    printArray(a, N);
    return 0;
}
