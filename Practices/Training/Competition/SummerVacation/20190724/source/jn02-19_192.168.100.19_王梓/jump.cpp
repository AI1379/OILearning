#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
int a[maxn+10][maxn+10];
bool vis[maxn+10][maxn+10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m,h,ans;

void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m) continue;
		if(abs(a[xx][yy]-a[x][y])>h) continue;
		if(!vis[xx][yy]) dfs(xx,yy);
	}
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n); read(m); read(h);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j])
				dfs(i,j),ans++;
	printf("%d\n",ans);
	return 0;
}
/*
input1:
3 4 1
2 0 0 0
0 0 2 2
0 0 2 2
output1:
3

input2:
1 9 2
1 3 2 4 7 5 9 6 8
output2:
4

input3:
2 3 1
1 6 5
2 3 4
output3:
1
*/
