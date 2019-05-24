#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack> 
#include <ctime>

using namespace std;

#define MAXN 5010

int n,m;
int x,y;
int son[MAXN][MAXN];
bool isuse[MAXN];
int ans[MAXN];
int now;
queue <int> q;

int main()
{
	memset(son,0,sizeof(son));
	memset(ans,0,sizeof(ans));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		son[x][++son[x][0]]=y;
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=5000;++i)
	{
		memset(isuse,true,sizeof(isuse));
		isuse[i]=false;
		q.push(i);
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			for(int j=1;j<=son[now][0];++j)
				if(isuse[son[now][j]])
				{
					isuse[son[now][j]]=false;
					++ans[i];
					q.push(son[now][j]);
				}
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		if(x>5000)printf("0 0\n");
			else printf("%d %d\n",son[x][0],ans[x]);
	}
	return 0;
}
