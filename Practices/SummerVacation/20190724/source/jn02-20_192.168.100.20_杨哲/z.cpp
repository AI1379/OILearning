#include<bits/stdc++.h>
using namespace std;
const int MAXN=50005;
int N,M,P,K,t[MAXN],u[MAXN],v[MAXN];
int x[MAXN],y[MAXN],z[MAXN],dp[MAXN],T;
void solve1(){
	for (int i=1;i<=N;i++) //dp[tmp]表示前I种甜品吃完后，至少达到J热量的最少体积。
		for (int j=P;j>=0;j--)
			for (int k=0;k<=v[i];k++){
				int tmp=j+k*t[i];
				tmp=min(tmp,P);
				dp[tmp]=min(dp[tmp],dp[j]+k*u[i]);
			}
	printf("%d\n",T=dp[P]);
}
void solve2(){
	memset(dp,0x7f7f7f,sizeof(dp)),dp[0]=0;
	for (int i=1;i<=M;i++)
		for (int j=T;j>=0;j--)
			for (int k=0;k<=z[i];k++){
				int tmp=j+k*x[i];
				tmp=min(tmp,T);
				dp[tmp]=min(dp[tmp],dp[j]+k*y[i]);
			}
	if (dp[T]<=K) printf("%d",dp[T]);
	else printf("FAIL");
}
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	memset(dp,0x7f7f7f,sizeof(dp));
	scanf("%d%d%d%d",&N,&M,&P,&K),dp[0]=0;
	for (int i=1;i<=N;i++)
		scanf("%d%d%d",&t[i],&u[i],&v[i]);
	for (int i=1;i<=M;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
	solve1(),solve2();
	return 0;
}
