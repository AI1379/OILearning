#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
int T;
LL L,R,ans,power[65];
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	power[0]=1ULL;
	for (int i=1;i<=62;i++) power[i]=power[i-1]*2ULL;
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld",&L,&R),ans=0ULL;
		if (L>R) swap(L,R);
		for (int i=ceil(log2(L+1));i<=ceil(log2(R+1));i++){
			int p=ceil(log2(power[i]-1-L));
			for (int j=0;j<=p&&j<i-1;j++)
				if (power[i]-1-power[j]>=L&&power[i]-1-power[j]<=R) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
