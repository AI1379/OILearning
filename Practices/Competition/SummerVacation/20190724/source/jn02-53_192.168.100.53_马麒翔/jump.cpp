#include<bits/stdc++.h>
using namespace std;
int mp[501][501];
bool yg[501][501];
bool p[501][501];
int a[4]{1,-1,0,0};
int b[4]{0,0,1,-1};
int ans=0;
int n,m,jp;
void dfs(int x,int y)
{
	for(int i=0;i<=3;i++)
	{
		if(yg[x+a[i]][y+b[i]]==1 && abs(mp[x][y]-mp[x+a[i]][y+b[i]])<=jp)
		{
			yg[x+a[i]][y+b[i]]=0;
			p[x+a[i]][y+b[i]]=1;
//			cout<<x+a[i]<<" "<<y+b[i]<<endl;
			ans++;
			dfs(x+a[i],y+b[i]);
			yg[x+a[i]][y+b[i]]=1;
		}
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>m>>jp;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			yg[i][j]=1;
		}
	}
	int cnt=0;
	int sum=n*m;
	while(ans<sum)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(p[i][j]==0)
				{
					yg[i][j]=0;
					p[i][j]=1;
//					cout<<i<<" "<<j<<"   ****"<<endl;
					ans++;
					dfs(i,j);
					yg[i][j]=1;
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
