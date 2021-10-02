#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,a,b,c,n1,n2,n3,ans,t[4];
/*a+b+c,a+2b,2a+b
1 1 1
1 2 0
2 1 0
若3种礼包的个数可以构成三角形，ans=三边之和 
否则，ans=两条短边之和*2+1
*/
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d%d",&a,&b,&c);
		for(n1=0;n1<=a&&n1<=b&&n1<=c;n1++)
			for(n2=0;n1+n2<=a&&n1+n2*2<=b;n2++)
				for(n3=0;n1+n2+n3*2<=a&&n1+n2*2+n3<=b;n3++){
					t[1]=n1,t[2]=n2,t[3]=n3;
					sort(t+1,t+4);
					if(t[1]+t[2]<t[3])
						ans=max(ans,(t[1]+t[2])*2+1);
					else
						ans=max(ans,t[1]+t[2]+t[3]);
				}
		printf("%d\n",ans);
	}
	return 0;
} 
