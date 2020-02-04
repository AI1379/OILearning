#include <bits/stdc++.h>
using namespace std;
int fa[30001], front[30001], num[30001], x, y, i, j, n, T, ans;
char ins;
int find(int n)
{
	if (fa[n] == n)
		return fa[n];
	int fn = find(fa[n]);	 
	front[n] += front[fa[n]];
	return fa[n] = fn;
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	front[fx] += num[fy];
	fa[fx] = fy;
	num[fy] += num[fx];
	num[fx] = 0;
	return ;
}
bool judge(int x,int y){
	return find(x)==find(y);
}
int main()
{
	cin >> T;
	for (i = 1; i <= 30000; ++i)
	{
		fa[i] = i;
		front[i] = 0;
		num[i] = 1;
	}
	while (T--)
	{
		cin >> ins >> x >> y;
		if (ins == 'M')
		{
			merge(x,y);
		}
		if (ins == 'C')
		{
			if (!judge(x,y))
				cout << "-1" << endl;
			else
				cout << abs(front[x] - front[y]) - 1 << endl;
		}
	}
	system("pause");
	return 0;
}