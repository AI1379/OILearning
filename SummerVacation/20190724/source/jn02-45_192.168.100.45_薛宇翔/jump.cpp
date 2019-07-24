#include<bits/stdc++.h>
using namespace std;
int a[501][501];
int dx[5]={1,0,-1,0},dy[5]={0,1,0,-1};
int q[3][501];
int H,W,M,front,rear,ans;
void bfs(int i,int j)
{
	front =1; rear=1;
	q[1][1]==i; q[2][1]==j;
	while(front<=rear)
	{
		for(int w=1;w<=4;w++)
		{
			if(a[q[1][front]+dx[w]][q[2][front]+dy[w]]-a[q[1][front]][q[2][front]]<=M)
			{
				rear++;
				q[1][rear]=q[1][front]+dx[w];
				q[2][rear]=q[2][front]+dy[w];
			}
			else if (a[q[1][front]+dx[w]][q[2][front]+dy[w]]-a[q[1][front]][q[2][front]]<=M)
			{
				rear++;
				q[1][rear]=q[1][front]+dx[w];
				q[2][rear]=q[2][front]+dy[w];
			}
			else ans++;
			front++;
		}
	}
}
int main()
{
	//freopen("jump.in","r",stdin);
	//freopen("jump.out","w",stdout);
	cin>>H>>W>>M;
	for (int i=1;i<=H;i++)
	{
		for (int j=1;j<=W;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=H;i++)
	{
		for (int j=1;j<=W;j++)
		{
			bfs(i,j);
		}
	}
	cout<<ans;
	return 0;
}
