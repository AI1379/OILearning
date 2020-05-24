#include <bits/stdc++.h>
using namespace std;
struct activity
{
    int s, f;
};
int n;
activity E[1000];
bool cmp(activity A, activity B)
{
    return A.f <= B.f;
}
int main()
{
    int i, latest = 0, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> E[i].s >> E[i].f;
    }
    sort(E, E + n - 1, cmp);
    for (i = 0; i < n; i++)
    {
        if (E[i].s >= latest)
        {
            latest = E[i].f;
            ans++;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}