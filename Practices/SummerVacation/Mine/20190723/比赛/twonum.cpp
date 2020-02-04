#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,k,m,h1,h2,a1,a2,x1,x2,y1,y2,t1,t2;
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>t;
	for(k=0;k<t;k++){
		cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
		if(a1>=m&&h1!=a1||a2>=m&&h2!=a2||(x1==0&&y1==0)||(x1==1&&y1==0&&h1%m!=a1)||(x2==0&&y2==0)||(x2==1&&y2==0&&h2%m!=a2)){
			cout<<"-1"<<endl;
			continue;
		}
		t1=0;
		t2=0;
		while(h1!=a1){
			h1=(x1*h1+y1)%m;
			t1++;
		}
		while(h2!=a2){
			h2=(x2*h2+y2)%m;
			t2++;
		}
		cout<<max(t1,t2)<<endl;
	}
	return 0;
}
