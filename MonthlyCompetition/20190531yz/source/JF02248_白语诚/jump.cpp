#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],f[10001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)f[i]=1<<30;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i-j<=a[j])f[i]=min(f[i],f[j]+1);
		}
	}
	cout<<f[n];
	return 0;
}
