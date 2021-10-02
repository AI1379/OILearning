#include<bits/stdc++.h>
using namespace std;
bool x[2][300][2][300];
int main() {
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int n;
	int lb=-1e7,ls=1e7,hb=-1e7,hs=1e7;
	int q,w;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>w>>q;
		lb=max(lb,w);
		ls=min(ls,w);
		hb=max(hb,q);
		hs=min(hs,q);
		if(q<0) {
			if(w<0) x[1][-q][1][-w]=1;
			else x[1][-q][0][w]=1;
		} else {
			if(w<0) x[0][q][1][-w]=1;
			else x[0][q][0][w]=1;
		}
	}
	bool flag=0;
	if(hs>0) hs=0;
	if(ls>0) ls=0;
	if(hb<0) hb=0;
	if(lb<0) lb=0;
	for(int i=hb; i>=hs; i--) {
		if(i==0) flag=1;
		for(int j=ls; j<=lb; j++) {
			if(flag==1) {
				if(j<0 && x[0][0][1][-j]==1) cout<<"*";
				else if(j>=0 && x[0][0][0][j]==1) cout<<"*";
				else {
					if(j==0) cout<<"+";
					else cout<<"-";
				}
				if(j==lb) flag=0;
			} else {
				bool o=0;
				if(i<0) {
					if(j<0 && x[1][-i][1][-j]==1) {
						cout<<"*";
						o=1;
					} else if(j>=0 && x[1][-i][0][j]==1) {
						cout<<"*";
						o=1;
					}
				} else if(j<0 && x[0][i][1][-j]==1) {
					cout<<"*";
					o=1;
				} else if(j>=0 && x[0][i][0][j]==1) {
					cout<<"*";
					o=1;
				}
				if(o==0) {
					if(j==0) cout<<"|";
					else cout<<".";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

