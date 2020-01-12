#include<bits/stdc++.h>
using namespace std;
long long i,n,a[5001],f[5001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1]=0;
	for (i=2;i<=n;i++)
	{
		f[i]=0x3f;
		for (long long k=i-1;k>=1;k--)
		{
			if (a[k]>=i-k)
			{
				f[i]=min(f[i],f[k]+1);
			}
		}
	}
	cout<<f[n];
	return 0;
} 
