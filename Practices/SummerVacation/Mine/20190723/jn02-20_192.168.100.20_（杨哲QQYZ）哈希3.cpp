#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=5005;
const ULL base=37;
const ULL MOD=100000007;
ULL N,ls,lt,p[MAXN],x[MAXN],y[MAXN],ans;
char S[MAXN],T[MAXN];
int main(){
	cin>>S,p[0]=1,ls=strlen(S);
	for (ULL i=1;i<=5000;i++)
		p[i]=p[i-1]*base%MOD;
	for (ULL i=1;i<=ls;i++)
		x[i]=(x[i-1]*base+(ULL)S[i-1])%MOD;
	cin>>N;
	while (N--){
		scanf("%s",T),y[0]=0,lt=strlen(T);
		for (ULL i=1;i<=lt;i++)
			y[i]=(y[i-1]*base+(ULL)T[i-1])%MOD;
		for (ULL i=1;i<=lt-ls+1;i++)
			if (x[ls]%MOD==(y[i+ls-1]-(y[i-1]*p[ls]%MOD)+MOD)%MOD) ans++;
	}
	printf("%lld",ans);
	return 0;
}
