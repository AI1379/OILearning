#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005],maxn=-1;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	for(int i=2; i<=n; i++)
	{
		int tmp=i-maxn,minn=10000;
		if(tmp<1) tmp=1;
		for(int j=tmp; j<i; j++)
		if(a[j]+j>=i&&f[j]<minn) minn=f[j];
		f[i]=minn+1;
	}
	cout<<f[n];
	return 0;
} 
