#include<bits/stdc++.h>
using namespace std;
int n,x[100001],y[100001],xx[100001],yy[100001],pdd;
double k;
int main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
	}
	if(n==1)
	{
    	double kk=x[1]*y[1],kkk=xx[1]*yy[1];
    	if(abs(kk)>abs(kkk))
    	{
    		k=kk;
		}
		else if(abs(kk)<abs(kkk))
		{
			k=kkk;
		}
		else if(kk<0)k=kk;else k=kkk;
		printf("%.2lf",k);return 0;
	}
	if(x[1]==xx[1])
	{
		for(int i=1;i<=n;++i)
		{
			double kk=x[i]*y[i];
			if(abs(kk)>abs(k))k=kk;
			else if(abs(kk)==abs(k))
			{
				if(kk<0)k=kk;
			}
		}
		printf("%.2lf",k);return 0;
	}
	cout<<"-1.00";
	return 0;
}
