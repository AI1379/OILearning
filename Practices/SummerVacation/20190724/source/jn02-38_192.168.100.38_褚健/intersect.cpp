#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n;
double xi,yi,xj,yj,ki,a,b,maxx;

int main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",&xi,&yi,&xj,&yj);
		a=(yj-yi)/(xj-xi);
		b=yi-a*xi;
		ki=-(b*b)/(4*a);
		if(ki>maxx) maxx=ki;
	}
	printf("%.2lf",maxx);
}
