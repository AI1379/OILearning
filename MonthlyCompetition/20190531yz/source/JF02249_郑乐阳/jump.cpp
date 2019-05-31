#include<bits/stdc++.h>
using namespace std;

int n,a[5005],f[6005];

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=0x7fffffff;
	}
	f[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=min(i+a[i],n);j++)
		{
			f[j]=min(f[j],f[i]+1);
		}
	}
	cout<<f[n];
	return 0;
}
/*
10
2 3 4 1 1 1 1 5 2 1000

10
2 3 4 7 1 1 1 5 2 1000
*/
