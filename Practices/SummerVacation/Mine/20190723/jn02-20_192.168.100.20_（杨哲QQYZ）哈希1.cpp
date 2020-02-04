#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=100005;
const ULL base=37;
const ULL MOD=100000007;
ULL ls,lt,p[MAXN],x[MAXN],y[MAXN];
string S,T;
int main(){
	cin>>S>>T,p[0]=1;
	ls=S.size(),lt=T.size();
	for (ULL i=1;i<=100000;i++)
		p[i]=p[i-1]*base%MOD;
	for (ULL i=1;i<=ls;i++)
		x[i]=(x[i-1]*base+(ULL)S[i-1])%MOD;
	for (ULL i=1;i<=lt;i++)
		y[i]=(y[i-1]*base+(ULL)T[i-1])%MOD;
	for (ULL i=1;i<=ls-lt+1;i++)
		if (y[lt]%MOD==(x[i+lt-1]-(x[i-1]*p[lt]%MOD)+MOD)%MOD) printf("%d\n",(int)i);
	return 0;
}
