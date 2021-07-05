#include <bits/stdc++.h>
using namespace std;
int n;
int lst[101];
int main()
{
    int i;
    cin >> n;
    for (i = n; i >= 0; i--)
        cin >> lst[i];
    for (i = n; i >= 0; i--)
    {
        if (lst[i] == 0)
            continue;
        else if (i == n && lst[i] != 1 && lst[i] != -1)
            cout << lst[i];
        else if (lst[i] == 1 && i != n)
            cout << '+';
        else if (lst[i] == -1)
            cout << '-';
        else if (lst[i] == 1 && i == n)
        {
        }
        else if (lst[i] > 0)
            cout << '+' << lst[i];
        else
            cout << lst[i];

        if (i != 0 && i != 1)
            cout << "x^" << i;
        else if (i == 1)
            cout << "x";

        if (i == 0 && (lst[i] == 1 || lst[i] == -1))
            cout << '1';
    }
    return 0;
}