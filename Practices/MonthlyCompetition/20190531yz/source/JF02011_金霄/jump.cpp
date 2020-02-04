#include<bits/stdc++.h>
using namespace std;
int f[5001],a[5001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)f[i]=1e9;
	f[1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(j+a[j]>=i)
			f[i]=min(f[i],f[j]+1);
		}
	}
	cout<<f[n];
	return 0;
 } 
