#include<bits/stdc++.h>
using namespace std;
int z=0;
double a[10],d=2.0,n,k;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%lf%lf",&n,&k);
	for(int i=0;i<k;i++){
		for(int j=0;j<4;j++){
			a[z%3]+=n;
			z++;
		}
		double m=d*(n/d)*(n/d);
		n=sqrt(m);
	}
	printf("%.3lf %.3lf %.3lf\n",a[0],a[1],a[2]);
	return 0;
}
