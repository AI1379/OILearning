#include<bits/stdc++.h>
using namespace std;

int n,a[1001],f[1001];

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(f,127,sizeof(f));
	f[1]=0;
	cin>>n;
	for(int i=1 ; i<=n ; i++)	
		cin>>a[i];
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=a[i]&&i+j<=n ; j++)
			f[i+j]=min(f[i+j],f[i]+1);
	cout<<f[n];
	return 0;//T2
} 
