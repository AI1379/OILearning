#include<bits/stdc++.h>
using namespace std;
bool zhuan(long long m){
	int sum=0,lo=0;
	int c[100]={0};
	long long tmp=m;
	while(tmp){
		lo++;
		if(tmp%2==0) c[lo]=0;
		else c[lo]=1;
		tmp/=2;
	}
	for(int d=1;d<=lo;d++)
		if(c[d]==0) sum++;
	if(sum==1) return true;
	else return false;
}
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	int t;
	long long l,r,ans=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ans=0;
		scanf("%lld%lld",&l,&r);
		for(long long j=l;j<=r;j++){
			if(zhuan(j)) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
