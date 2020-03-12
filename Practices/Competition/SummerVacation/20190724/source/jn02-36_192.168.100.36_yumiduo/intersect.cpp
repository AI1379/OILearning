#include<bits/stdc++.h>
using namespace std;
int n,ax[100001],ay[100001],bx[100001],by[100001],ans[200001],k;
int main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d%d",ax+i,ay+i,bx+i,by+i);
	for(int i=1;i<=n;i++)
	{
		ans[i]=ax[i]*ay[i];
		ans[n+i]=bx[i]*by[i];
	}
	for(int i=1;i<=2*n;i++)
	k=max(k,abs(ans[i]));
	for(int i=1;i<=2*n;i++)
	{
		if(k==abs(ans[i]))
		printf("%.2lf",(double)k);
	}
	return 0;
}
