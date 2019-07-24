#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long l,r,ans=0;
		cin>>l>>r;
		int ai=l/2*2;
		for(int j=l;j<=r;j++){	
				int a=0,b=j;
				while(b>0){
					int c=b%2;
				    b/=2;
				    if(c==0) a++;
				}
				if(a==1) ans++;
		}
		cout<<ans;
	}
	return 0;
}
