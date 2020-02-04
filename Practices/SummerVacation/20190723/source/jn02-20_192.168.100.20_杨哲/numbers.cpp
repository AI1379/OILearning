#include<bits/stdc++.h>
using namespace std;
const int MAXN=305;
const int MOD=100000007;
int T,M,N,dp[MAXN][MAXN];
int main(){
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&M,&N);
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=300;i++) dp[0][i]=dp[1][i]=1;
		for (int i=1;i<=300;i++) dp[i][1]=1;
		for (int i=2;i<=M;i++)
			for (int j=2;j<=N;j++){
				if (i<j) dp[i][j]=1;
				else dp[i][j]=(dp[i-j][j]+dp[i][j-1])%MOD;
			}
		printf("%d\n",dp[M][N]%MOD);
	}
	return 0;
}
