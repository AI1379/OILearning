#include<bits/stdc++.h>
using namespace std;
long long t,a,b,c,ans;
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	scanf("%lld",&t);
	for(long long i=0;i<t;i++){
		ans=0;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a>c&&b>c){
			a-=c;
			b-=c;
			ans+=c;
		}
		else{
			ans+=min(a,b);
			printf("%lld\n",ans);
			continue;
		}
		if(a>=2*b){
			ans+=b;
		}
		else if(b>=2*a){
			ans+=a;
		}
		else if(a>=b){
			while(b>0&&a<2*b){
				a-=3;
				b-=3;
				ans+=2;
			}
			if(a>=2*b){
				ans+=b;
			}
		}
		else{
			while(a>0&&b<2*a){
				a-=3;
				b-=3;
				ans+=2;
			}
			if(b>=2*a){
				ans+=a;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
