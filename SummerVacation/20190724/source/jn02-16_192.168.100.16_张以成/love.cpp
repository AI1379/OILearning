#include<bits/stdc++.h>
using namespace std;
inline void fop(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	return;
}
int t,l,r;
int ans;
bool alt[60];
int to(int i){
	int j=0,l=0;
	while(i){
		alt[j]=i%2;
		j++;
		l+=i%2;
		i=i/2;
	}
	for(int k=0;k<j/2;k++){
		swap(alt[k],alt[j-k-1]);
	}
	if((j-l)!=0){
		return j-l;
	}
	else{
		return -j;
	}
}
inline void mn(){
	cin>>l>>r;
	int t;
	for(int i=l;i<=r;i++){
		t=to(i);
		if(t==1){
			ans+=1;
		}
		else{
			if(t<0){
				t=-t;
				break;
			}
		}
	}
	int tt=to(r);
	for(int i=r;i>=l&&tt!=t;i--){
		if(tt==1){
			ans+=1;
		}
		else{
			if(tt<0){
				tt=-tt;
				break;
			}
		}
		tt=to(i-1);
	}
	for(int i=t;i<tt;i++){
		ans+=(i-1);
	}
	cout<<ans;
	return;
}
int main(){
	fop();
	cin>>t;
	ans=0;
	for(int i=0;i<t;i++){
		mn();
	}
	return 0;
}

