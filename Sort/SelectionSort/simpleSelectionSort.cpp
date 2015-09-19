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

void simpleSelectionSort(int a[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        int pos = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[pos] )
            {
                pos = j;
            }
        }
        swap(&a[i], &a[pos]);
    }
}

int main()
{
    int a[N] = {6, 5, 4, 0, 2, 1, 9, 8, 3, 7};
    printArray(a, N);
    simpleSelectionSort(a, N);
    printArray(a, N);
    return 0;
}
