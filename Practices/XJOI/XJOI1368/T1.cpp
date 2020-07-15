#include <bits/stdc++.h>
#ifdef DEBUG
#include <windows.h>
#endif
using namespace std;
int n;
int tower[10000];
int update(int left, int right)
{
    if (right - left <= 2)
    {
        return 0;
    }
    int min = 1 << 30, minIndex, i;
    for (i = left; i < right; i++)
    {
        if (tower[i] < min)
        {
            minIndex = i;
            min = tower[i];
        }
    }
#ifdef DEBUG
    printf("(%d,%d),%d,[%d]\n", left, right, min, minIndex);
    Sleep(10);
#endif
    return update(left, minIndex - 1) + update(minIndex + 1, right) + min;
}
int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> tower[i];
    }
#ifdef DEBUG
    for (i = 0; i < n; i++)
    {
        cout << tower[i] << ' ';
    }
    cout << endl;
#endif
    cout << update(0, n);
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}