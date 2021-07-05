//luogu P5661

#include <bits/stdc++.h>
using namespace std;
struct ticket
{
    int time;
    int price;
};
vector<ticket> q;
int n, ans = 0;
int main()
{
    int i, x, y, z;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        if (x == 0)
        {
            ticket tmp;
            ans += y;
            tmp.price = y, tmp.time = z;
            q.push_back(tmp);
#ifdef DEBUG
            cout << i << ' ';
#endif
        }
        if (x == 1)
        {
            if (q.empty())
            {
                ans += y;
#ifdef DEBUG
                cout << i << ' ';
#endif
                continue;
            }
            bool flag = false;
            for (int j = 0; j < q.size();)
            {
                if ((z - q[j].time <= 45) && (y <= q[j].price))
                {
                    flag = true;
                    q.erase(q.begin() + j);
                    break;
                }
                if (y > q[j].price)
                {
                    j++;
                    continue;
                }
                q.erase(q.begin() + j);
            }
            if (flag)
                continue;
            else
            {
#ifdef DEBUG
                cout << i << ' ';
#endif
                ans += y;
            }
        }
    }
    cout << ans;
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}