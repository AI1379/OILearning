#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int ans[10000];
	int g[10000];
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",&g[i]);
	}
	if(a==1){
		printf("0");
		return 0;
	}
	if(a==2){
		printf("1");
		return 0;
	}
	memset(ans,0,sizeof(ans));
	ans[a-1]=0;
	ans[a-2]=1;
	for(int i=a-3;i>=0;i--){
		ans[i]=ans[i+1]+1;
		if(g[i]!=1){
			for(int j=i;j<=min(i+g[i],a-1);j++){
				if(ans[j]+1<ans[i]){
					ans[i]=ans[j]+1;
				}
			}
		}
	}
	printf("%d",ans[0]);
	return 0;
} 
