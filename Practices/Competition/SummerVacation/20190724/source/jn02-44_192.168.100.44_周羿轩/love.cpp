#include<bits/stdc++.h>
#define l long long
l a,b,s1,s2,ss1,ss2,z,ans,t;
using namespace std;
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>b) a^=b,b^=a,a^=b;
		while(a){
			s1++;
			if(a%2==0) ss1=s1;
			a/=2;
		}
		if(s1==0) s1++,ss1++;
		while(b){
			s2++;
			if(b%2==0) ss2=s2,z++;
			b/=2;
		}
		if(z==1) ss2++;
		if(s2!=s1){
			ans+=s2-ss2;
			ans+=ss1-1;
			if(s1==1) ans++;
			if(s2==1) ans++;
		}
		else ans+=max(ss2,ss1)-min(ss2,ss1)+1;
		for(l i=s1+1;i<s2;i++){
			ans+=i-1;
			if(i==1) ans++;
		}
		cout<<ans<<endl;
		ss1=ss2=s1=s2=ans=0;
	}
	return 0;
}
