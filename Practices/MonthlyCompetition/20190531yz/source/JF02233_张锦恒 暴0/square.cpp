#include<bits/stdc++.h>
using namespace std;

int k,z;
double f,zc,a[4];

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	f=sqrt(2);
	cin>>zc>>k;
	for(int i=1 ; i<=k ; i++)
	{
		for(int j=1 ; j<=4 ; j++)
		{
			z++;
			if(z==4) z=1;
			a[z]+=zc;
		}
		zc/=f;
	}
	printf("%.3lf %.3lf %.3lf",a[1],a[2],a[3]);
	return 0;//T1
} 
