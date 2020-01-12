#include<bits/stdc++.h>
using namespace std;
int n,a[5001],f[5001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),f[i]=0x7f7f7f7f;
	f[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			if(i+j<=n)
	 		f[i+j]=min(f[i+j],f[i]+1);
		}
	}
	cout<<f[n];
	return 0;
}
