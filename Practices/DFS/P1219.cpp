#include <bits/stdc++.h>
using namespace std;
int ans[15];
int vis[15][15];
int n;
long long sum = 0;
void dfs(int dep)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		if (!vis[dep][i])
		{
			ans[dep] = i;
			for (j = dep; j <= n; j++)
				vis[j][i]++;
			for (j = 1; j <= n - dep && j <= i - 1; j++)
				vis[dep + j][i - j]++;
			for (j = 1; j <= n - dep && j <= n - i; j++)
				vis[dep + j][i + j]++;
			if (dep == n)
			{
				sum++;
				if (sum <= 3)
				{
					for (j = 1; j <= n; j++)
					{
						cout << ans[j] << ' ';
					}
					cout << endl;
				}
			}
			if (dep < n)
				dfs(dep + 1);
			for (j = dep; j <= n; j++)
				vis[j][i]--;
			for (j = 1; j <= n - dep && j <= i - 1; j++)
				vis[dep + j][i - j]--;
			for (j = 1; j <= n - dep && j <= n - i; j++)
				vis[dep + j][i + j]--;
		}
	}
	return;
}
int main()
{
	cin >> n;
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	dfs(1);
	cout << sum;
	return 0;
}