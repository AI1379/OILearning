#include <bits/stdc++.h>
using namespace std;
int W,H,w,h,k,ansh,ansz,t1,t2;
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	if(w>W&&w>H||h>W&&h>H){
		cout<<"-1"<<endl;
		return 0;
	}
	if(w>W&&w<=H){
       swap(w,h);
	}
	if(h>H&&w<=W){
      swap(w,h);
	}
	t1=w;
	t2=h;
	while(1){
		if(t1>=W){
			break;
		}
		t1*=2;
		ansh++;
	}
	while(1){
		if(t2>=H){
			break;
		}
		t2*=2;
		ansz++;
	}
	cout<<ansh+ansz;
	return 0;
}
