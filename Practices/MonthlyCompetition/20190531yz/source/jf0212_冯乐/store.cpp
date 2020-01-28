#include<bits/stdc++.h>
using namespace std;
long long t,a,b,c;
long long f,sum;
int main(){
	freopen("store.in","r",stdin);
    freopen("store.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		if(c==0){
			f=min(a/3,b/3);
			f=f*2;
		}
		else{
			if(a==1&&b==1){
				cout<<"1";
				continue;
			}
			if(a>=b){
				sum=min(a/2,b);
				f=min(sum,c);
				f=f*2;
			}
			else{
				sum=min(a,b/2);
				f=min(sum,c);
				f=f*2;
			}
		}
		cout<<f<<endl;
	}
	return 0;
}
