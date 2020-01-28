#include<bits/stdc++.h>
using namespace std;
int n,k;
double a[4];
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=4;j++)
		a[(4*(i-1)+j)%3]+=(double)n/pow(sqrt(2),i-1);
	}
	printf("%.3lf %.3lf %.3lf",a[1],a[2],a[0]);
	return 0;
 } 
