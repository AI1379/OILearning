#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y;
};
point p[510];
int n;
long long ans = 0;
bool judge(point a, point b, point c)
{
    if ((a.x - b.x) * (b.y - c.y) == (a.y - b.y) * (b.x - c.x))
    {
        return false;
    }
    int d1, d2, d3, delta;
    d1 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    d2 = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
    d3 = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
    delta = d1 + d2 + d3 - max(max(d1, d2), d3);
    return delta < 0;
}
int main()
{
    int i, j, k;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            for (k = j; k < n; k++)
            {
                if (judge(p[i], p[j], p[k]) && i != j && i != k && j != k)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}