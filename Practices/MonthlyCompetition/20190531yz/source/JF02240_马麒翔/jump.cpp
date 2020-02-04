#include<bits/stdc++.h>
using namespace std;
int a[5005];
int f[5005][5005];
int main() {
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,o;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		for(int j=1; j<=n; j++) {
			f[i][j]=5001;
		}
	}
	f[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				f[i][j]=0;
				continue;
			}
			else
			{
				for(int k=1;k<=a[i];k++)
				{
					f[i][j]=min(f[i][j-k]+1,f[i][j]);
				}
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
