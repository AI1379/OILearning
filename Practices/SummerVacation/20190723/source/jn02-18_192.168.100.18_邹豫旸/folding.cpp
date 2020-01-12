#include<bits/stdc++.h>
using namespace std;
int w11,w22,h11,h22,ans,ans1;
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%d%d%d%d",&w11,&h11,&w22,&h22);
	int w1=w11,h1=h11,w2=w22,h2=h22;
	while(1){
		if(w1==w2) break;
		if(w1<w2){
			ans=-1; break;
		} 
		if(w1-w2>w1/2){
			ans++; w1-=w1/2;
		} 
		else{
			ans++; break;
		}
	}
	if(ans!=-1){
		while(1){
		    if(h1==h2) break;
		    if(h1<h2){
			    ans=-1; break;
		    } 
		    if(h1-h2>h1/2){
			    ans++; h1-=h1/2;
		    } 
		    else{
			    ans++; break;
		    }
	    }
	}
	w1=w11,h1=h11,w2=w22,h2=h22;
	while(1){
		if(w1==h2) break;
		if(w1<h2){
			ans1=-1; break;
		} 
		if(w1-h2>w1/2){
			ans1++; w1-=w1/2;
		} 
		else{
			ans1++; break;
		}
	}
	if(ans1!=-1){
		while(1){
		    if(h1==w2) break;
		    if(h1<w2){
			    ans1=-1; break;
		    } 
		    if(h1-w2>h1/2){
			    ans1++; h1-=h1/2;
		    } 
		    else{
			    ans1++; break;
		    }
	    }
	}
	cout<<max(ans,ans1);
	return 0;
}
