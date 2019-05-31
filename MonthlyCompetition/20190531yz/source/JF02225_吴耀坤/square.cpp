#include<iostream>
#include<cmath> 
#include<cstdio>
using namespace std; 
int n,k;
double ans,p=sqrt(2)*0.5,now,a[3];

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	now=n;
	for(int i=1;i<=4*k;i++)
	{
		a[i%3]+=now;
		if(i%4==0)
			now*=p;
	}
	printf("%.3f %.3f %.3f",a[1],a[2],a[0]);	
}
/*
100

*/
