#include <bits/stdc++.h>
using namespace std;
int m, s, c, ans;
int cows[200];
int diff[200];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int i;
    cin >> m >> s >> c;
    for (i = 0; i < c; i++)
    {
        cin >> cows[i];
    }
    if (m > c)
    {
        cout << c;
        return 0;
    }
#ifdef DEBUG
    cout << "================\n";
#endif // DEBUG
    sort(cows, cows + c);
#ifdef DEBUG
    for (i = 0; i < c; i++)
    {
        cout << cows[i] << ' ';
    }
    cout << endl;
#endif // DEBUG
    ans = cows[c - 1] - cows[0] + 1;
#ifdef DEBUG
    cout << ans << endl;
#endif // DEBUG
    diff[0] = 0;
    for (i = 1; i < c; i++)
    {
        diff[i] = cows[i] - cows[i - 1];
    }
    sort(diff, diff + c, cmp);
#ifdef DEBUG
    for (i = 0; i < c; i++)
    {
        cout << diff[i] << ' ';
    }
    cout << endl;
#endif // DEBUG
    for (i = 0; i < m - 1; i++)
    {
        ans -= diff[i];
        ans++;
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif // DEBUG
    return 0;
}