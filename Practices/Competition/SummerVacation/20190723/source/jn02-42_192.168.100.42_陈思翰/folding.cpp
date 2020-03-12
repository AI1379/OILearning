#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	int W,H,w,h,ans1=0,ans2=0,W1,H1;
	cin>>W>>H>>w>>h;
	W1=W;
	H1=H;
	if(max(W,H)<max(w,h)){
		cout<<"-1";
		return 0;
	}
	if(W>=w&&H>=h){
		while(H>2*h){
			if(H%2)H=H/2+1;
			else H/=2;
			ans1++;
		}
		if(H>h)ans1++;
		while(W>2*w){
			if(W%2)W=W/2+1;
			else W/=2;
			ans1++;
		}
		if(W>w)ans1++;
	}
	else ans1=1e9;
	if(W1>=h&&H1>=w){
		while(H1>2*w){
			if(H1%2)H1=H1/2+1;
			else H1/=2;
			ans2++;
		}
		if(H1>w)ans2++;
		while(W1>2*h){
			if(W1%2)W1=W1/2+1;
			else W1/=2;
			ans2++;
		}
		if(W1>h)ans2++;
	}
	else ans2=1e9;
	cout<<min(ans1,ans2);
	return 0;
}
