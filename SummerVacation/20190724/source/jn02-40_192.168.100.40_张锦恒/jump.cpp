#include <bits/stdc++.h>
#define LoL long long
using namespace std;

int H,W,m,ans;
int f[501][501];

void bl(int x,int y)
{
	int k=f[x][y];
	f[x][y]=1000;
	if((f[x+1][y]<=k+m)&&(f[x+1][y]>=k-m)&&(f[x+1][y]!=1000))
		bl(x+1,y);
	if(f[x-1][y]<=k+m&&f[x-1][y]>=k-m&&f[x-1][y]!=1000)
		bl(x-1,y);
	if(f[x][y+1]<=k+m&&f[x][y+1]>=k-m&&f[x][y+1]!=1000)
		bl(x,y+1);
	if(f[x][y-1]<=k+m&&f[x][y-1]>=k-m&&f[x][y-1]!=1000)
		bl(x,y-1);
	return;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	for(int i=0 ; i<=500 ; i++)
		for(int j=0 ; j<=500 ; j++)
			f[i][j]=1000;
	cin>>H>>W>>m;
	for(int i=1 ; i<=H ; i++)
		for(int j=1 ; j<=W ; j++)
			cin>>f[i][j];
	for(int i=1 ; i<=H ; i++)
		for(int j=1 ; j<=W ; j++)
			if(f[i][j]!=1000)
			{
				bl(i,j);
				ans++;
			}
	cout<<ans;
	return 0;
}
