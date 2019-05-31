#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring>
using namespace std;
int n,f[6000],a[6000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	memset(f,127/3,sizeof(f));
	f[1]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=1;i+j<=n&&j<=a[i];j++)
		{
			f[i+j]=min(f[i]+1,f[i+j]);
		}
	}
	cout<<f[n];
}
/*
15
4 5 2 1 3 2 1 2 3 4 2 3 1 2  5
*/
