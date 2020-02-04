#include<bits/stdc++.h>
using namespace std;
long long f[301];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	cin>>T;
	for(int i1=1; i1<=T; i1++) {
		memset(f,0,sizeof(f));
		int n,r;
		cin>>r>>n;
		f[0]=1;
		for(int i=1; i<=n; i++)
			for(int j=r; j>=i; j--) {
				for(int k=1; k<=j/i; k++) {
					f[j]+=f[j-k*i];
					f[j]%=100000007;
				}
			}
		cout<<f[r]<<endl;
	}
	return 0;
}
