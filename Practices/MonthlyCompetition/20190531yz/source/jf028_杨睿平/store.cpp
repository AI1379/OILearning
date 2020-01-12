#include <bits/stdc++.h>
using namespace std;
int t;
int ans;
void dfs(int a,int b,int c,int ste,int gif){
	//cout<<a<<" "<<b<<" "<<c<<" "<<ste<<endl;
	if(a<=0||b<=0){
		if(a<0||b<0){
			ste-=1;
		}
		if(ans<ste){
			ans=ste;
		}
		return;
	}
    if(gif!=1){
    	dfs(a-2,b-1,c,ste+1,1);
	}
	if(gif!=2){
		dfs(a-1,b-2,c,ste+1,2);
	}
	if(gif!=3&&c>=1){
		dfs(a-1,b-1,c-1,ste+1,3);
	}
}
int main(){
	freopen("store.in","r",stdin);
    freopen("store.out","w",stdout);
	scanf("%d",&t);
	int i,j;
	int a,b,c;
	for(i=1;i<=t;i++){
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		dfs(a,b,c,0,0);
		printf("%d\n",ans);
	}
	return 0;
} 
