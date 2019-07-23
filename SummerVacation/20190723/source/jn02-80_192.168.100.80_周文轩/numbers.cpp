//#include<bits/stdc++.h>
#include<cstdio>
//#include<>
//using namespace std;
inline int read(){
	register int x;register char c(getchar());register bool k;
	//while((c<'0'||c>'9')&&c^'-')if((c=getchar())==EOF)exit(0);
	if(c^'-')x=c-'0',k=1;else x=0,k=0;
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return k?x:((~x)+1);
}
int T,m,n;
long long ans;
const long long Mo=100000007;
void dfs(int i,int be,int se){
	if(se==0){
		ans++;
		ans%=Mo;
		//printf("%d %d %d\n",ans,i,be);
		return;
	}
	if(se<be)return;
	if(i==n)return;
	for(int j=be;j<=se;j++){
		dfs(i+1,j,se-j);
	}
}
long long f[301][301][301]={0};
int main(){
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&m,&n);
		//dfs(0,1,m);
		for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
		for(int k=0;k<=300;k++)f[i][j][k]=0;
		f[0][0][0]=1;
		for(int i=1;i<=n;i++){
			for(int k=0;k<=m;k++){
				for(int j=0;j<=k;j++){//j*(n-i+1)<=m-k
					for(int t=0;t<=j;t++){
						f[i][j][k]=f[i][j][k]+f[i-1][t][k-j];
					}
				}
			}
		}
		/*
		for(int i=0;i<=n;i++){
			for(int k=0;k<=m;k++){
				for(int j=0;j<=m;j++){
					printf("%lld ",f[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}*/
		for(int j=0;j<=m;j++){
			ans+=f[n][j][m];
			ans%=Mo;
		}
		printf("%lld\n",ans);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
