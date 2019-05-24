#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
long long c,k,n,l,r;
double a,t;
const double zero=0,acc=5e-6;
bool flag;
double sqr(double x){
	return x*x;
} 
int main(){
	//freopen("science.in","r",stdin);
	//freopen("science.out","w",stdout);
	long long i,j;
	scanf("%lf%lld",&a,&k);
	c=floor(a);
	a=a-floor(a);
	n=(long long)sqrt(k);
	for(i=0;i<=n;i++){
		l=ceil(sqr(max(zero,i+a-acc)));
		r=min((long long)floor(sqr(i+a+acc)),k);
		if(l>k)
			break;
		for(j=l;j<=r;j++){
			printf("%lld %lld\n",j,c-i);
			flag=1;
		}
	}
	if(!flag) 
		printf("Silly fnk\n");
	return 0;
}
