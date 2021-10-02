#include<bits/stdc++.h>
using namespace std;
const int INF=1<<29;
long long n,a[5001],f[5001];
int main(){
	freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	f[i]=INF;
	} 
    f[1]=0;
    for(int i=2;i<=n;i++){
    	for(int j=1;j<i;j++){
    		if(a[j]>=(i-j)) f[i]=min(f[i],f[j]);
		}
		f[i]++;
	}
	cout<<f[n];
	return 0;
}
