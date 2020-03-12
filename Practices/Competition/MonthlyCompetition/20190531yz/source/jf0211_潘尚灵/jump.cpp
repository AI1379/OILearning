#include<bits/stdc++.h> 
using namespace std;
int a[50005],f[50005];
int ans=1e9+1;
int flag;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,i,j;
	cin>>n;
	f[n]=0;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
		f[i]=1e9;
	for(i=n-1;i>0;i--)
	{
		flag=0;
		for(j=1;j<=a[i];j++)
		{
			if(i+j>n) 
			{
				flag=1;
				break;
			}
			if(f[i+j]<ans)
			{
				ans=f[i+j];
			}	
		}	
		if(flag=1)
			f[i]=f[n]+1;
		else 
			f[i]=ans+1;
	}
	ans=f[1]+1;
	cout<<ans<<endl;
	return 0;
 } 
