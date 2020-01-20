#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 250;
long long phi[255], pri[255];
bool vis[255];
long long f[210];
long long nop;
long long init()
{
    long long i, j, cnt = 0;
    phi[1] = 1;
    memset(vis, false, sizeof(vis));
    for (i = 2; i < MAXN; ++i)
    {
        if (!vis[i])
        {
            phi[i] = i - 1;
            pri[cnt++] = i;
        }
        for (j = 0; j < cnt; ++j)
        {
            if (1ll * i * pri[j] >= MAXN)
                break;
            vis[i * pri[j]] = true;
            if (i % pri[j])
            {
                phi[i * pri[j]] = phi[i] * (pri[j] - 1);
            }
            else
            {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
        }
    }
//    cnt--;
    return cnt;
}
int main()
{
    long long i, j, q;
    nop = init();
    f[0] = 0;
    f[1] = 0;
    for (i = 0; i < nop; i++)
    {
        f[pri[i]]++;
    }
    for(i=0;i<=nop;i++)cout<<pri[i]<<' ';
    cout<<endl;
    for (i = 2; i <= 200; i++)
    {
        for (j = 1; pri[j] * 2 <= i && j <= nop; j++)
        {
            f[i] += f[i - pri[j]];
        }
    }
    for(i=0;i<=200;i++)cout<<i<<':'<<f[i]<<' ';
    system("pause");
/*    while (cin >> q)
    {
        cout << f[q] << endl;
    }*/
    return 0;
}