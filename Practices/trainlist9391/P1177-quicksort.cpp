#include <bits/stdc++.h>
using namespace std;
const int ins = 16;
int a[100000];
int n;
void insertsort(int left, int right)
{
    int i, j, key;
    for (i = left + 1; i <= right; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= left && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return;
}
inline int choosePiovt(int left, int right)
{
    int x = left, y = right, z = (left + right) / 2;
    if ((y <= x && x <= z) || (z <= x && x <= y))
        return x;
    else if ((x <= y && y <= z) || (z <= y && y <= x))
        return y;
    else if ((x <= z && z <= y) || (y <= z && z <= x))
        return z;
    else
    {
        srand(time(NULL));
        return (rand() % (right - left + 1) + left);
    }
}
void quicksort(int left, int right)
{
    if (right - left < 1)
        return;
#ifndef DEBUG
    if (right - left <= ins)
    {
        // #ifdef DEBUG
        //         cout << "Use Insert Sort..." << endl;
        // #endif
        insertsort(left, right);
        return;
    }
// #ifdef DEBUG
//     cout << "Use Quick Sort..." << endl;
// #endif
#endif
    int key = choosePiovt(left, right), pivot = a[key];
    int i = left, j = right, k = left;
    while (k < j)
    {
        if (a[k] < pivot)
            swap(a[k++], a[i++]);
        else if (a[k] > pivot)
            swap(a[k], a[j--]);
        else
            k++;
    }
#ifdef DEBUG
    cout << left << ' ' << right << endl;
    for (int m = left; m <= right; m++)
        cout << a[m] << ' ';
    cout << endl;
#endif
    quicksort(left, i - 1);
    quicksort(j, right);
    return;
}
int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    quicksort(0, n - 1);
    for (i = 0; i < n; i++)
        cout << a[i] << ' ';
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}