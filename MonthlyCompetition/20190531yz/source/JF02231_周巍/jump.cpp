#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,f[5005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];	
	if(n==1){
		cout<<0<<endl;
		exit(0);
	}
	f[1]=0;
	for(int i=2;i<=n;i++)
    {
    	f[i]=1e9;
    	for(int j=1;j<i;j++)
    	{
    		if((i-j)<=a[j]) f[i]=min(f[i],f[j]);	
		}
		f[i]++;
	}
	cout<<f[n]<<endl;
	return 0;
}
