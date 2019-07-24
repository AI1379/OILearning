//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath> 
//#include<>
using namespace std;
inline int read(){
	register int x;register char c(getchar());register bool k;
	//while((c<'0'||c>'9')&&c^'-')if((c=getchar())==EOF)exit(0);
	if(c^'-')x=c-'0',k=1;else x=0,k=0;
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return k?x:((~x)+1);
}
bool vi[502][502]={false};
int Map[502][502]={0};
int H,W,M,ans=0;
void dfs(int i,int j){
	vi[i][j]=true;
	if(!vi[i-1][j]&&(abs(Map[i][j]-vi[i-1][j])<=M))dfs(i-1,j);
	if(!vi[i][j-1]&&(abs(Map[i][j]-vi[i][j-1])<=M))dfs(i,j-1);
	if(!vi[i+1][j]&&(abs(Map[i][j]-vi[i+1][j])<=M))dfs(i+1,j);
	if(!vi[i][j+1]&&(abs(Map[i][j]-vi[i][j+1])<=M))dfs(i,j+1);
	
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	for(int i=0;i<=501;i++){
		for(int j=0;j<=501;j++){
			Map[i][j]=-500;
			vi[i][j]=false;
		}
	}
	scanf("%d%d%d",&H,&W,&M);
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			scanf("%d",&Map[i][j]);
		}
	}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(!vi[i][j]){
				ans++;
				dfs(i,j);
			}
		}
	}
	printf("%d",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
