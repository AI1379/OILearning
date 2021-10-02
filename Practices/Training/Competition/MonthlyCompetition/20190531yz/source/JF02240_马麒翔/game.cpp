#include<bits/stdc++.h>
using namespace std;
long long a[5][5];
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,o;
	int x,y,z;
	string g;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>x>>y>>z;
		cin>>g;
		a[x][y]=z;
		if(g=="U") {
			for(int l=1; l<=4; l++) {
				int t=0,tx=0;
				for(int j=1; j<=4; j++) {
					if(a[j][l]>0) {
						if(t==0) t=a[j][l],tx=j;
						else if(t>0) {
							if(a[j][l]==t) {
								a[tx][l]*=2;
								a[j][l]=0;
								t=0;
								tx=0;
							} else {
								t=a[j][l];
								tx=j;
							}
						}
					}
				}
				for(int o=4; o>=2; o--) {
					if(a[o][l]>0 && a[o-1][l]==0) a[o-1][l]=a[o][l],a[o][l]=0;
				}
			}
		}
	
		else if(g=="D") {
			for(int l=1; l<=4; l++) {
				int t=0,tx=0;
				for(int j=4; j>=1; j--) {
					if(a[j][l]>0) {
						if(t==0) t=a[j][l],tx=j;
						else if(t>0) {
							if(a[j][l]==t) {
								a[tx][l]*=2;
								a[j][l]=0;
								t=0;
								tx=0;
							} else {
								t=a[j][l];
								tx=j;
							}
						}
					}
				}
				for(int o=1; o<=3; o++) {
					if(a[o][l]>0 && a[o+1][l]==0) a[o+1][l]=a[o][l],a[o][l]=0;
				}
			}
		}

		else if(g=="L") {
			for(int j=1; j<=4; j++) {
				int t=0,tx=0;
				for(int k=1; k<=4; k++) {
					if(a[j][k]>0) {
						if(t==0) t=a[j][k],tx=k;
						else if(t>0) {
							if(a[j][k]==t) {
								a[j][k]*=2;
								a[j][tx]=0;
								t=0;
								tx=0;
							} else {
								t=0;
								tx=0;
							}
						}
					}
				}
				for(int k=4; k>=2; k--) {
					if(a[j][k]>0 && a[j][k-1]==0) {
						a[j][k-1]=a[j][k],a[j][k]=0;
						k+=2;
					}
				}
			}
		}

		else if(g=="R") {
			for(int j=1; j<=4; j++) {
				int t=0,tx=0;
				for(int k=4;k>=1;k--) {
					if(a[j][k]>0) {
						if(t==0) t=a[j][k],tx=k;
						else if(t>0) {
							if(a[j][k]==t) {
								a[j][k]*=2;
								a[j][tx]=0;
								t=0;
								tx=0;
							} else {
								t=0;
								tx=0;
							}
						}
					}
				}
				for(int k=1;k<=3;k++) {
					if(a[j][k]>0 && a[j][k+1]==0) {
						a[j][k+1]=a[j][k],a[j][k]=0;
						k-=2;
					}
				}
			}
		}
		
		bool flag=1;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				if(a[i][j]==0)
				{
					flag=0;
					break;
				}
			}
			if(flag==0) break;
		}
		if(flag==1)
		{
			cout<<"Game over!"<<endl;
			return 0;
		}
	}
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
