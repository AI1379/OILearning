#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int N,a[MAXN],dp[MAXN];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(dp,0x7f7f7f,sizeof(dp));
	scanf("%d",&N),dp[0]=dp[1]=0;
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	for (int i=2;i<=N;i++)
		for (int j=1;j<=i-1;j++)
			if (j+a[j]>=i) dp[i]=min(dp[i],dp[j]+1);
	printf("%d",dp[N]);
	return 0;
}
