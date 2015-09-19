#include <iostream>

#define N 10
using namespace std;

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int a[], int n)
{
    int i, j;
    bool changed = true;
    for(i = n - 1; i > 0 && changed; i--)
    {
        changed = false;
        for(j = 0 ; j < i; j++)
        {
            if(a[j] > a[j + 1] )
            {
                swap(&a[j], &a[j + 1]);
                changed = true;
            }
        }
    }
}

int main()
{
    int a[N] = {6, 5, 4, 0, 2, 1, 9, 8, 3, 7};
    printArray(a, N);
    bubbleSort(a, N);
    printArray(a, N);
    return 0;
}
