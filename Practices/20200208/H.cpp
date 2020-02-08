#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
bitset<100001> is_prime;
bitset<100001> vis;
vector<map<int, int>> prilst;
map<int, int> rst;
int ans[100001];
int difpri[100001];
int num;
int init(int x)
{
    int p = 0;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= x; ++i)
    {
        if (is_prime[i])
        {
            p++;
            prime.push_back(i);
            for (int j = i * i; j <= x; j += i)
                is_prime[j] = 0;
        }
    }
    return p;
}
int getnum(int x)
{
    int i;
    int tmp = x;
    rst[x] = 1;
    for (i = 2; i <= x; i++)
    {
        prilst[x][i] = 0;
    }
    if (is_prime[x])
    {
        difpri[x] = 1;
        prilst[x][x] = 1;
        return 0;
    }
    for (i = 0; prime[i] <= tmp && tmp > 1; i++)
    {
        while (tmp > 1 && tmp % prime[i] == 0)
        {
            tmp /= prime[i];
            if (vis[tmp])
            {
                rst[x] = (rst[tmp] + difpri[tmp] + 1) / (prilst[tmp][prime[i]] + 1) * (prilst[tmp][prime[i]] + 2) - difpri[tmp] - 1;
                prilst[x][prime[i]] = prilst[tmp][prime[i]] + 1;
                difpri[x] = difpri[tmp];
                if (prilst[tmp][prime[i]] == 0)
                {
                    rst[x]--;
                    difpri[x]++;
                }
                return rst[x];
            }
            if (prilst[x][prime[i]] == 0)
                difpri[x]++;
            prilst[x][prime[i]]++;
        }
    }
    for (i = 2; i <= x; i++)
    {
        rst[x] *= (prilst[x][i] + 1);
    }
    rst[x] -= difpri[x];
    rst[x]--;
    vis[x] = true;
    return rst[x];
}
int main()
{
    int n, m, k;
    int i;
    vis.reset();
    cin >> n >> m;
    prilst.resize(n + 1);
    num = init(n);
    for (i = 2; i <= n; i++)
    {
        ans[getnum(i)]++;
    }
    for (i = 0; i < m; i++)
    {
        cin >> k;
        cout << ans[k] << endl;
    }
    return 0;
}