#include<bits/stdc++.h>
using namespace std;

int w,H,h[505][505],m;
bool vis[505][505];
int ans;
int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

struct aaa
{
	int x,y,t;
};

void bfs(int xs,int ys)
{
	queue<aaa> q;
	aaa cur,nex;
	cur.x=xs;
	cur.y=ys;
	cur.t=0;
	vis[xs][ys]=1;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		nex.t=cur.t+1;
		for(int i=0;i<4;i++)
		{
			nex.x=cur.x+dis[i][0];
			nex.y=cur.y+dis[i][1];
			if(nex.x>=1&&nex.x<=H&&nex.y>=1&&nex.y<=w) 
			{
				if(vis[nex.x][nex.y]==0&&abs(h[nex.x][nex.y]-h[cur.x][cur.y])<=m)
				{
					vis[nex.x][nex.y]=1;
					q.push(nex);
				}
			}
		}
	}
}

int main()
{ 
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&H,&w,&m);
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=w;j++)
		{
			scanf("%d",&h[i][j]);
		}
	}
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(vis[i][j]==0)
			{
				ans++;
				bfs(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
6 2 2
1 2
2 5
3 3
9 7
5 4
7 9

3 4 1
0 2 0 2
0 0 2 2
0 2 0 0

4 5 2
1 2 3 4 2
9 7 8 5 1
6 0 0 7 0
10 10 10 10 10


*/
