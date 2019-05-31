#include<bits/stdc++.h>
using namespace std;
const int MAXN=35;
int T,A,B,C,dp[MAXN][MAXN][MAXN][3],dp2[1000005][3];
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	scanf("%d",&T);
	if (T>=50){
		while (T--){
			memset(dp2,0,sizeof(dp));
			scanf("%d%d%d",&A,&B,&C);
			for (int i=3;i<=A+B+C;i++){
				dp2[i][1]=max(dp2[i-3][2],dp2[i-3][3])+1;
				dp2[i][2]=max(dp2[i-3][1],dp2[i-3][3])+1;
				dp2[i][3]=max(dp2[i-3][1],dp2[i-3][2])+1;
			}
			printf("%d\n",max(dp2[A+B+C][1],max(dp2[A+B+C][2],dp2[A+B+C][3])));
		}
		return 0;
	}
	while (T--){
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d",&A,&B,&C);
		for (int i=0;i<=A;i++)
			for (int j=0;j<=B;j++)
				for (int k=0;k<=C;k++){
					if (i>=1&&j>=1&&k>=1) dp[i][j][k][1]=max(dp[i-1][j-1][k-1][2],dp[i-1][j-1][k-1][3])+1;
					if (i>=1&&j>=2) dp[i][j][k][2]=max(dp[i-1][j-2][k][1],dp[i-1][j-2][k][3])+1;
					if (i>=2&&j>=1) dp[i][j][k][3]=max(dp[i-2][j-1][k][1],dp[i-2][j-1][k][2])+1;
				}
		printf("%d\n",max(dp[A][B][C][1],max(dp[A][B][C][2],dp[A][B][C][3])));
	}
	return 0;
}
