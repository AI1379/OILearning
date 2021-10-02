#include <bits/stdc++.h>
using namespace std;
long long l,r,T;
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%lld",&T);
	long long i,j,s,kt,ans;
	while(T>0){
	    T--;
	    ans=0;
	    bool f,f2=0;
	    scanf("%lld%lld",&l,&r);
	    for(i=l;i<=r;i++){
	    	f=0;
	    	s=i;
	    	while(s>0){
	    		if(s%2==0&&f==1){
	    			f=0;
	    			break;
				}
				if(s%2==0&&f==0)f=1;
				s/=2;
			}
			if(f)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
