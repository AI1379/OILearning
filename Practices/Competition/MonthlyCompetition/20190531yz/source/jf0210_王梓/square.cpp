#include<bits/stdc++.h>
using namespace std;
double a[10],n,num;
int ci=-1,k;
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k; num=n;
	for(int i=1;i<=k;i++)
	{
		for(int i=1;i<=4;i++)
			ci=(ci+1)%3,
			a[ci]+=num;
		num=sqrt(num*num/2*1.0);
	}
	printf("%.3lf %.3lf %.3lf\n",a[0],a[1],a[2]);
	return 0;
}
