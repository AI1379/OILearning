//Coded by dst
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll l,r;
int T;
ll solve(){
	ll res=0,i,j,t0=0,t;
	for(i=1;t0<=r;i++){//枚举0的位置 
		if(i>1)
			t0=t0+(1ll<<(i-2));
		for(j=i+1,t=t0;t<=r;j++){//枚举位数 
			t=t+(1ll<<(j-1));
			res+=(l<=t&&t<=r);
		}
	}
	return res;	
}
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve());
	}
	return 0;
} 
