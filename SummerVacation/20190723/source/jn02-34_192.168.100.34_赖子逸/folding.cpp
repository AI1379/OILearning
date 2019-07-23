#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout); 
	int w,h,w1,h1,ans=0;
	cin>>w>>h>>w1>>h1;
	if(w>h) swap(w,h);
	if(w1>h1) swap(w1,h1);
	int a=w,b=h;
	if(max(w1,h1)>max(w,h)){
		cout<<"-1";
		return 0;
	}
	for(;a>w1,b>h1;){
		if(a>w1){
			if(a>2*w1)
			    a=a/2;
			else
			   a=w1;
			ans++;
		}
		else{
			if(b>2*h1)
			    b=b/2;
			else 
			    b=h1;
			ans++;
		}
	}
	if(a==w1&&b==h1){
		cout<<ans;
		return 0;
	}
	cout<<"-1";
	return 0;
}
