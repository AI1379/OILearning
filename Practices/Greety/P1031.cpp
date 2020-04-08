#include <bits/stdc++.h>
using namespace std;
int n, avg = 0, ans = 0;
int cards[100];
int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> cards[i];
        avg += cards[i];
    }
    avg /= n;
    for (i = 0; i < n; i++)
    {
        cards[i] -= avg;
    }
    for (i = 0; i < n; i++)
    {
        if (cards[i] == 0)
        {
            continue;
        }
        else
        {
            cards[i + 1] += cards[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}