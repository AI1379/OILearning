#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int n, i, x;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        q.push(x);
    }
    int ans = 0, tmp;
    while (!q.empty())
    {
        tmp = q.top();
        q.pop();
        if (q.empty())
            break;
        tmp += q.top();
        q.pop();
        q.push(tmp);
        ans += tmp;
    }
    cout << ans;
    return 0;
}