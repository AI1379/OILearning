#include<bits/stdc++.h>
using namespace std;

int dp[205],w[205],v[205],n,m,p,k,x[205],y[205],z[205];
int tot=0;

//dp[i][j]=min(dp[i-1][j],dp[i][j+w[i]]);

int main()
{
	int n,bag,p,h,c;
	cin>>n>>m>>bag>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&h,&p,&c);
		int tmp=1;
		while(c>=tmp)
		{
			w[++tot]=tmp*h;
			v[tot]=tmp*p;
			c-=tmp;
			tmp<<=1;
		}
		if(c)
		{
			v[++tot]=p*c;
			w[tot]=h*c;
		}
	}
	for(int i=0;i<=bag;i++)
		dp[i]=ceil(1.0*i/w[1]);
	for(int i=2;i<=tot;i++)
		for(int j=0;j<=bag;j++)
		{
			if(j+w[i]<=bag)
				dp[j]=min(dp[j],dp[j+w[i]]-v[i]);
		}
	cout<<dp[bag]<<endl;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	cout<<"FAIL";
	return 0;
}



