#include<bits/stdc++.h>
using namespace std;
int t[201],u[201],v[201],x[201],y[201],z[201],f[20001][201],n,m,k,p,n1[101][101],n2[101][101];
int main()
{
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&t[i],&u[i],&v[i]);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	int minn=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=v[i];j++)
			n1[i][j]=u[i]*j;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=z[i];j++)
			n2[i][j]=y[i]*j;
	for(int i=1;f[i-1][0]<p;i++,minn++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<=v[j];k++)
			{
				if (i-u[j]*k>=0)
					if (f[i-n1[j][k]][j]+k<=v[j])
					{
						if (f[i][0]<=f[i-n1[j][k]][0]+t[j]*k)
						{
							f[i][0]=f[i-n1[j][k]][0]+t[j]*k;
							for (int l=1;l<=n;l++)
								f[i][l]=f[i-n1[j][k]][l];
							f[i][j]+=k;
						}
					}
				else
					break;
			}
		}
	}
	memset(f,0,sizeof(f));
	cout<<minn<<endl;
	int minnn=0;
	for (int i=1;minn>f[i-1][0];i++,minnn++)
	{
		for (int j=1;j<=m;j++)
		{
			for (int k=0;k<=z[j];k++)
			{
				if (i-n2[j][k]>=0)
					if (f[i-n2[j][k]][j]+k<=z[j])
					{
						if (f[i][0]<=f[i-n2[j][k]][0]+x[j]*k)
						{
							f[i][0]=f[i-n2[j][k]][0]+x[j]*k;
							f[i][j]=f[i-n2[j][k]][j]+k;
							for (int l=1;l<=n;l++)
								f[i][l]=f[i-n2[j][k]][l];
							f[i][j]+=k;
						}
					}		
				else
					break;
			}
		}	
		if (minnn>k)
		{
			cout<<"FAIL\n";
			return 0;
		}
	}
	cout<<minnn<<endl;
	return 0;
}
