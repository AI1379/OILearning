#include <bits/stdc++.h>
using namespace std;

const int mo=100000007;
long long f[301][301][301];

int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	long long tot=0,t,m,n;
	for(int j=1 ; j<=300 ; j++)
		f[1][j][j]=1,
		f[j][j][1]=1;
	f[1][0][0]=1;
	for(int i=2 ; i<=160 ; i++)
	 for(int j=0 ; j<=160 ; j++)
	  for(int k=0 ; k<=j ; k++)
	  {
	  	f[i][j][k]=0;
	  	for(int kk=0 ; kk<=k ; kk++)
	  	 f[i][j][k]=(f[i][j][k]+f[i-1][j-k][kk])%100000007;
	  }
	cin>>t;
	for(int i=1 ; i<=t ; i++)
	{
		tot=0;
		cin>>m>>n;
		for(int j=1 ; j<=m ; j++)
			tot=(tot+f[n][m][j])%100000007;
		cout<<tot<<endl;
	}
	return 0;
}
