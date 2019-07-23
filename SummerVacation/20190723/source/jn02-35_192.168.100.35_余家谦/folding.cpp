#include<bits/stdc++.h>
using namespace std;
int temp,ans;
double w1,h1,w2,h2;
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>w1>>h1>>w2>>h2;
	if(w1<h1){
		temp=w1;
		w1=h1;
		h1=temp;
	}
	if(w2<h2){
		temp=w2;
		w2=h2;
		h2=temp;
	}
	if(w1<w2||h1<h2){
		cout<<-1;
		return 0;
	}
	while(w1>w2){
		w1/=2;
		ans++;
	}
	while(h1>h2){
		h1/=2;
		ans++; 
	}
	cout<<ans;
	return 0;
}
