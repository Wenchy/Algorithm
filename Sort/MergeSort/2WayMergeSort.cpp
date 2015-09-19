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

// lpos = start of left half
// rpos = start of right half
void merge(int A[], int T[], int lpos, int rpos, int rend)
{
    int lend, NElements, tpos;
    lend = rpos - 1;
    NElements = rend - lpos + 1;
    tpos = lpos;
    // main loop
    while(lpos <= lend && rpos <= rend)
    {
        if(A[lpos] <= A[rpos])
            T[tpos++] = A[lpos++];
        else
            T[tpos++] = A[rpos++];
    }

    while(lpos <= lend) // copy rest of left half
        T[tpos++] = A[lpos++];
    while(rpos <= rend) // copy rest of right half
        T[tpos++] = A[rpos++];

    // Copy T[] back
    for(int i = 0; i < NElements; i++, rend--)
    {
        A[rend] = T[rend];
    }
}

void MSort(int A[], int T[], int left, int right)
{
    int center;
    if(left < right)
    {
        center = (left + right) / 2;
        MSort(A, T, left, center);
        MSort(A, T, center + 1, right);
        merge(A, T, left, center + 1, right);
    }
}

void MergeSort(int A[], int n)
{
    int *T = new int[n * sizeof(int)];
    if(!T)
    {
        cerr << "new error" << endl;
    }

    MSort(A, T, 0, n - 1);
    delete [] T;
}

int main()
{
    int a[N] = {6, 5, 4, 0, 2, 1, 9, 8, 3, 7};
    printArray(a, N);
    MergeSort(a, N);
    printArray(a, N);
    return 0;
}
