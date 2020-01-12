#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,ans;
int main(){
	freopen("store.in","r",stdin);
    freopen("store.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    	cin>>a>>b>>c;
    	ans=0;
    	while(a*b*c!=0){
    	if(a>=1&&b>=1&&c>=1){
    		a-=1;
    		b-=1;
    		c-=1;
    		ans++;
		}
		if(a>=2&&b>=1){
    		a-=2;
    		b-=1;
    		ans++;
		}	
		if(a>=1&&b>=2){
    		a-=1;
    		b-=2;
    		ans++;
		}
		}
		cout<<ans;
	}
	return 0;
} 
