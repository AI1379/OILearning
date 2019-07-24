//Q2:love.Coded by Yjq.
#include<bits/stdc++.h>
using namespace std;
int t,l,r;
string vary(int x){
	string s="";
	while(x!=0){
		s=(char)(x%2+'0')+s;
		x/=2;
	}
	if(s==""){
		return "0"; 
	}
	return s;
}
bool check(string s){
	int w=s.size(),amt=0;
	for(int i=0;i<w;i++){
		if(s[i]=='0'){
			amt++;
		}
		if(amt==2){
			return false;
		}
	}
	if(amt==0){
		return false;
	}else{
		return true;
	}
}
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			if(check(vary(j))){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
