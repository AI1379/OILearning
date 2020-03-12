#include<bits/stdc++.h>
using namespace std;
double square(double x,double y)
{
	return sqrt(x*x+y*y);
}
double A,M,G;
double a,b,c;
int op=1;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%lf%lf",&a,&b);
	for(int i=1;i<=b;i++)
	{
		if(i==1) c=a;
		else c=square(a,a);
		for(int j=1;j<=4;j++)
		{
			if(op%3==1) A+=c;
			else if(op%3==2) M+=c;
			else if(op%3==0) G+=c;
			op++;
		}
		a/=2;
	}
	printf("%.3lf %.3lf %.3lf",A,M,G);
	return 0;
 } 
