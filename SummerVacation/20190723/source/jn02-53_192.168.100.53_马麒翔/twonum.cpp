#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1; i<=T; i++) {
		long long h1,a1,x1,y1,h2,a2,x2,y2,m;
		long long ans=0;
		
		cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
		bool y[m+1][m+1];
		memset(y,false,sizeof(y));y[h1][h2]=1;
		while(1) {
			if(h1==a1 && h2==a2) {
				cout<<ans<<endl;
				break;
			} else {
				h1=(h1*x1+y1)%m;
				h2=(h2*x2+y2)%m;
				ans++;
				if(y[h1][h2]==0) {
					y[h1][h2]=1;
				} else {
					cout<<"-1"<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

