#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=1005;
const ULL base=37;
const ULL MOD=100000007;
ULL N,l[MAXN],p[MAXN],h[MAXN][MAXN],tmp,L,R,mid,ans;
string S[MAXN];
bool judge(int p1,int p2,int pos){
	if (h[p1][pos]==h[p2][pos]) return true;
	return false;
}
int main(){
	scanf("%d",&N),p[0]=1;
	for (ULL i=1;i<=N;i++) cin>>S[i],l[i]=S[i].size();
	for (ULL i=1;i<=1000;i++) p[i]=p[i-1]*base%MOD;
	for (ULL i=1;i<=N;i++)
		for (ULL j=1;j<=l[i];j++)
			h[i][j]=(h[i][j-1]*base+(ULL)S[i][j-1])%MOD;
	for (ULL i=1;i<=N;i++)
		for (int j=1;j<=N;j++){
			if (i==j) continue;
			tmp=0,L=0,R=max(l[i],l[j]);
			while (L<=R){
				mid=(L+R)>>1;
				if (judge(i,j,mid)) L=mid+1,tmp=mid;
				else R=mid-1;
			}
			ans+=tmp;
		}
	printf("%lld",ans);
	return 0;
}
