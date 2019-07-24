#include<bits/stdc++.h>
using namespace std;
int N;
long long ax,ay,bx,by;
double ans;
int main(){
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	scanf("%d",&N);
	if (N==1){
		scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
		if (ax==bx&&ay==by) printf("%.2lf",(double)labs(ax*ay));
		else if (ax>bx&&ay>by) printf("%.2lf",(double)labs(ax*ay));
		else if (ax<bx&&ay<by) printf("%.2lf",(double)labs(bx*by));
		else printf("%.2lf",fabs(((double)(ax+bx)/2.0)*((double)(ay+by)/2.0)));
	}
	else printf("QQYZ Boom Zero.");
	return 0;
}
