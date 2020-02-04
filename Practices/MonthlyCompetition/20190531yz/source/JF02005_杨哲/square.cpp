#include<bits/stdc++.h>
using namespace std;
const double p=sqrt(2.0)/2.0;
int K;
double N,tmp,ans[5];
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%lf%d",&N,&K),tmp=N;
	for (int i=1;i<=K*4;i++){
		if (i!=1&&i%4==1) tmp*=p;
		ans[(i-1)%3+1]+=tmp;
	}
	printf("%.3lf %.3lf %.3lf",ans[1],ans[2],ans[3]);
	return 0;
}
