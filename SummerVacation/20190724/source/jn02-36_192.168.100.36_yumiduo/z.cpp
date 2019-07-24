#include<bits/stdc++.h>
using namespace std;
int n,m,r,v,u,k,t1;
int a[501],ge[501],c[501];
int f[100001];
int main()
{
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&v,&r);
	for(int i=0;i<=50000;i++)
	f[i]=0x7f7f7f7f;
    f[0]=0;
    for(int i=1;i<=n;i++)
    scanf("%d%d%d",&a[i],&c[i],&ge[i]);
    for(int i=1;i<=n;i++)
    {
		for(int j=v;j>=0;j--)
    	{
    		for(int k=0;k<=ge[i];k++)
          	{
			  	t1=j+k*a[i];
          		if(t1>v)
		   		t1=v;
           		if(f[t1]>f[j]+k*c[i])
		  	 	f[t1]=f[j]+k*c[i];
			}
        }
	}
    printf("%d\n",f[v]);
    v=f[v];
    for(int i=0;i<=50000;i++)
	f[i]=0x7f7f7f7f;
    f[0]=0;
    for(int i=1;i<=m;i++)
    scanf("%d%d%d",&a[i],&c[i],&ge[i]);
    for(int i=1;i<=m;i++)
    {
		for(int j=v;j>=0;j--)
    	{
    		for(int k=0;k<=ge[i];k++)
          	{
			  	t1=j+k*a[i];
          		if(t1>v)
		   		t1=v;
           		if(f[t1]>f[j]+k*c[i])
		  	 	f[t1]=f[j]+k*c[i];
			}
        }
	}
    if(f[v]<=r)
    printf("%d",f[v]);
    else
    printf("FAIL");
    return 0;
  }

