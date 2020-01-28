#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int mx[5]={0,0,-1,1},my[5]={-1,1,0,0},map[601][601],vis[601][601];
int h,w,m,times;

void bfs(int x,int y)
{
	queue <int> qx;queue <int> qy;
	int xi,yi;
	qx.push(x),qy.push(y);
	vis[x][y]=1;
	while(qx.size())
	{
		xi=qx.front(),yi=qy.front();
		qx.pop(),qy.pop();
		for(int i=0;i<4;i++)
		{
			if(((map[xi+mx[i]][yi+my[i]]-map[xi][yi])>=(-m))&&((map[xi+mx[i]][yi+my[i]]-map[xi][yi])<=m&&(!vis[xi+mx[i]][yi+my[i]])))
			{
				qx.push(xi+mx[i]),qy.push(yi+my[i]);
				vis[xi+mx[i]][yi+my[i]]=1;
			}
		}
	}
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	for(int i=0;i<=600;i++)
		for(int j=0;j<=600;j++)
			map[i][j]=-1000000;
	scanf("%d%d%d",&h,&w,&m);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(!vis[i][j]) bfs(i,j),times++;
	printf("%d",times);
}
