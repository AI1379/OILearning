#include<bits/stdc++.h>
using namespace std;
double W,H,w,h;
int ans1,ans2,ans;
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%lf%lf%lf%lf",&W,&H,&w,&h);
	if ((w>W&&h>H)||(w>H&&h>W)||(w>W&&w>H)||(h>W&&h>H)){
		printf("-1");
		return 0;
	}
	if (w>W||h>H) swap(w,h);
	ans1=ceil(log2(W/w))+ceil(log2(H/h));
	if (w>H||h>W){
		printf("%d",ans=ans1);
		return 0;
	}
	swap(w,h),ans2=ceil(log2(W/w))+ceil(log2(H/h));
	ans=min(ans1,ans2);
	printf("%d",ans);
	return 0;
}
