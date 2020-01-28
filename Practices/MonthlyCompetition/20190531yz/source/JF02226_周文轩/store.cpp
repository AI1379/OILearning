#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
bool pd(int n){
	int ta=a,tb=b,tc=c;
	if(ta<n)return false;
	if(tb<n)return false;
	ta-=n,tb-=n;
	if(ta+tb+tc<n)return false;
	if(ta+tb+1<n-ta-tb)return false;
	if(ta+tc+1<n-ta-tc)return false;
	if(tc+tb+1<n-tb-tc)return false;
	return true;
} 
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		int l=0,r=1000000,mid;
		while(l<r){
			mid=(l+r)/2;
			if(pd(mid))l=mid+1;
			else r=mid;
		}
		cout<<r-1<<endl;
	}
	return 0;
}
