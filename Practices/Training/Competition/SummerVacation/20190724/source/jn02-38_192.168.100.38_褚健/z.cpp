#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int t[210],u[201],v[201],x[210],y[210],z[210],f[50010],d[50010];
int n,m,p,k;

int main()
{
	memset(f,127/3,sizeof(f));
	memset(d,127/3,sizeof(d));
	d[0]=f[0]=0;
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&t[i],&u[i],&v[i]);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for(int i=1;i<=n;i++)
		for(int k=1;k<=v[i];k++)
			for(int j=p;j>=0;j--)
			{
				int s=min(p,j+k*t[i]);
				if(s>=k*t[i])
					f[s]=min(f[s],f[s-k*t[i]]+k*u[i]);
			}
	printf("%d\n",f[p]);
	for(int i=1;i<=m;i++)
		for(int k=1;k<=z[i];k++)
			for(int j=f[p];j>=0;j--)
			{
				int s=min(f[p],j+k*x[i]);
				if(s>=k*x[i])
					d[s]=min(d[s],d[j]+k*y[i]);
			}
	if(d[f[p]]>k) printf("FAIL");
	else printf("%d",d[f[p]]);
}
