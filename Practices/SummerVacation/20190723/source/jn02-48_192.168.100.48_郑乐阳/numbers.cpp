#include<bits/stdc++.h>
using namespace std;

#define mod 100000007

int t,m,n,dp[305][305];

int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%d",&t);
	dp[1][1]=1;
	for(int i=0;i<=300;i++)
		dp[0][i]=1;
	for(int i=2;i<=300;i++)
	{
			for(int j=1;j<=i;j++)
			{
				for(int k=1;k<=j;k++)
				{
					dp[i][j]=(dp[i][j]+dp[i-j][k]*dp[j][k])%mod;
				}
			}
		}
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&m,&n);
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=dp[n][j];
		}
		cout<<sum;
	}
	return 0;
}

