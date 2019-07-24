#include <bits/stdc++.h>
using namespace std;
long long biao[2000],gs=0;
long long t[100];
void ycl(){
	t[0]=1;
	for(int i=1;i<=60;i++){
		t[i]=t[i-1]*2;
	}
	for(int i=1;i<=60;i++){
		for(int j=i-1;j>=1;j--){
			biao[gs]=t[i]-1-t[j-1];
			gs++;
		}
	}
}
long long tl,l,r;
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%lld",&tl);
	ycl();
	for(int i=0;i<tl;i++){
		int ans=0;
		scanf("%lld%lld",&l,&r);
		for(int j=0;;j++){
			if(biao[j]>r){
				break;
			}else if(biao[j]<=r&&biao[j]>=l){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
