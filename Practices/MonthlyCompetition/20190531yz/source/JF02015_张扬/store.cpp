#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	int a,b,c,d,ans;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		ans=0;
		scanf("%d%d%d",&b,&c,&d);
		if(c!=0){
			int lea=min(min(b,c),min(b,d));
			b-=lea;
			c-=lea;
			d-=lea;
			ans+=lea;
		}
		if(b>c){
			ans+=b/2;
		}else if(b<c){
			ans+=c/2;
		}else{
			ans+=b/2;
		}
		printf("%d",ans);
		if(i!=a-1){
			printf("\n");
		}
	}
	return 0;
} 
