#include <iostream>
#define CUTOFF 3
#define N 10
using namespace std;

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

// get median of left, center, and right
// order these amd hide the pivot
int median3(int a[], int left, int right)
{
    int center = left + (right - left)/2;
    if(a[left] > a[center])
        swap(&a[left], &a[center]);
    if(a[left] > a[right])
        swap(&a[left], &a[right]);
    if(a[center] > a[right])
        swap(&a[center], &a[right]);

    // hide pivot
    swap(&a[center], &a[right - 1]);
    // return pivot
    return a[right - 1];
}

void printArray(int a[], int n)
{
    for(int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
}

void insertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        if(a[i] < a[i - 1])
        {
            int j;
            int temp = a[i];
            for(j = i - 1; j >= 0 && temp < a[j]; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}

int partition(int a[], int left, int right)
{
    int i, j;
    int pivot;
    pivot= median3(a, left, right);
    i = left;
    j = right - 1;
    while(1)
    {
        while(a[++i] < pivot);
        while(a[--j] > pivot);
        if(i < j)
            swap(&a[i], &a[j]);
        else
            break;
    }
    // restore pivot
    swap(&a[i], &a[right - 1]);
    return i;

}
void quickSort(int a[], int left, int right)
{
    if(left + CUTOFF <= right)
    {
        int pos = partition(a, left, right);
        quickSort(a, left, pos - 1);
        quickSort(a, pos + 1, right);
    } else {
        // do an insertion sort on the subarray
        // for small quantity, insertion sort is effective
        insertionSort(a + left, right - left + 1);
    }
}

int main()
{
    int a[N] = {4, 1, 3, 4, 7, 0, 2, 13, -3, -1};
    int b[N] = {4, 1, 3, 4, 7, 0, 2, 13, -3, -1};

    cout << "insertion sort: "<< endl;
    printArray(a, N);
    insertionSort(b, N);
    printArray(b, N);

    cout << "quick sort: "<< endl;
    printArray(a, N);
    quickSort(a, 0, N - 1);
    printArray(a, N);
    return 0;
}
