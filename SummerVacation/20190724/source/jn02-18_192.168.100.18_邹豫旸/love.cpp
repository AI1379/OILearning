#include<bits/stdc++.h>
#define int long long
using namespace std;
int t; long long a,b;
signed main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&a,&b);
		int al=0,bl=0,ao=0,bo=0,ans=0,f=0;
		if(a==0) ans++;
		while(a){
			al++;
			if(a%2==0) ao=al; 
			a/=2;
		}
		ans-=(al-ao-1); 
		while(b){
			bl++;
			if(b%2==0){
				bo=bl;
				f++;
			}
			b/=2;
		}
		ans-=bo; if(f==1) ans++;
		for(int i=al; i<=bl; i++) ans+=(i-1);
		printf("%lld\n",ans);
	}
	return 0;
}
