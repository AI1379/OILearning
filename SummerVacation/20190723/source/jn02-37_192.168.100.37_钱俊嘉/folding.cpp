#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	double W,H,w,h,ans=0;
	cin>>W>>H>>w>>h;
	if(W<H) swap(W,H);
	if(w<h) swap(w,h);
	if(W<w||H<h) cout<<-1;
	else{
		while(W/2>=w){
			W/=2;
			ans++;
		}
		if(W!=w) ans++;
		while(H/2>=h){
			H/=2;
			ans++;
		}
		if(H!=h) ans++;
		cout<<ans;	
	}
	return 0;	
}
