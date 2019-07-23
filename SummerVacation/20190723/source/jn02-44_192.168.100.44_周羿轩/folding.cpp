#include<bits/stdc++.h>
#define l long long
using namespace std;
l w,h,t1,t2;
long double W,H;
l f(long double W,long double H,l w,l h){
	if(W<w||H<h) return -1;
	l a=0;
	while(W>2*w){
		a++;
		W/=2.0;
	}
	if(W>w) a++;
	while(H>2*h){
		a++;
		H/=2.0;
	}
	if(H>h) a++;
	return a;
}
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	t1=f(W,H,w,h);
	t2=f(W,H,h,w);
	if(t1==-1) cout<<t2;
	else if(t2==-1) cout<<t1;
	else cout<<min(t1,t2);
	return 0;
} 
