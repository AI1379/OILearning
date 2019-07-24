#include<bits/stdc++.h>
using namespace std;

int s[501][501];

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,m,c,ans=1;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(((s[i][j+1]>s[i][j]+c)||(s[i][j+1]<s[i][j]-c))&&((s[i+1][j]>s[i][j]+c)||(s[i+1][j]<s[i][j]-c)))
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
