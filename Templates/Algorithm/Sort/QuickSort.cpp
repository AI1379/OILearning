#include <bits/stdc++.h>
usind namespace std;
const int MAX_LENGTH_INSERT_SORT = 7;
void InsertSort(int *L)
{
}
int Partition(int *L, int low, int high)
{
    int pivotkey;
    int m = low + (high - low) / 2;
    if (L[low] > L[high])
    {
        L[low] ^= L[high];
        L[high] ^= L[low];
        L[low] ^= L[high];
    }
    if (L[m] > L[high])
    {
        L[high] ^= L[m];
        L[m] ^= L[high];
        L[high] ^= L[m];
    }
    if (L[m] > L[low])
    {
        L[low] ^= L[m];
        L[m] ^= L[low];
        L[low] ^= L[m];
    }
    pivotkey = L[low];
    int tmp = pivotkey;
    while (low < high)
    {
        while (low < high && L[high] >= pivotkey)
            high--;
        L[low] = L[high];
        while (low < high && L[low] <= pivotkey)
            low++;
        L[high] = L[low];
    }
    L[low] = tmp;
    return low;
}
void QSort(int *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        while (low < high)
        {
            pivot = Partition(L, low, high);
            QSort(L, low, pivot - 1);
            low = pivot + 1;
        }
    }
    else
        InsertSort(L);
}
int main()
{
}