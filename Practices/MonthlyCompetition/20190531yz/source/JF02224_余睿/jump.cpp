#include<iostream>
#include<cstdio>
using namespace std;
int a[5001],b[5001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=5001;
	}
	b[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(a[i],n);j++)
			b[i+j]=min(b[i+j],b[i]+1);
	}
	cout<<b[n]<<endl;
	return 0;
}
