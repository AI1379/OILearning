#include<bits/stdc++.h>
using namespace std;
const int mod=1e8+7;
int ans[301][301],m,n,t;
int main() {
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	for(int m=0; m<=300; m++)
		for(int n=0; n<=300; n++) {
			if(n==1||m==0) ans[m][n]=1;
			else if(m<n) ans[m][n]=ans[m][m];
			else ans[m][n]=(ans[m][n-1]+ans[m-n][n])%mod;
		}
    cin>>t;
    while(t--){
    	cin>>m>>n;
    	cout<<ans[m][n]<<endl;
	}
}
