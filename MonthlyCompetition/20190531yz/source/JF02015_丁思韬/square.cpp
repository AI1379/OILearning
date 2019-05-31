#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double n,a[4005],temp=sqrt(2),ans[4];
int k;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int i;
	scanf("%lf%d",&n,&k);
	for(i=0;i<k;i++,n=n/2*temp)
		a[i*4+1]=a[i*4+2]=a[i*4+3]=a[i*4+4]=n;
	for(i=1;a[i];i++)
		ans[i%3]+=a[i];
	printf("%.3lf %.3lf %.3lf",ans[1],ans[2],ans[0]);
	return 0;
} 
