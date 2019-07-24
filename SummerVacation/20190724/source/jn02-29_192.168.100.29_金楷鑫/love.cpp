#include<bits/stdc++.h>
using namespace std;
int main()
{   
    freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	long long l,r;
	int t,x,y,z,b=0,c=1,ans=0,max=1;
	long long a[70];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>l>>r;
		if(l==r) cout<<"1"<<endl;
		else{
		if(r>max-1)
		{
		for(long long j=max;j<=r;j=max)
		{
		  max=max*2;
	      b++;
		  a[b]=max-1;
		}
		}
        for(int j=1;j<=b;j++)
		{
		  if(a[j+1]>=l&&a[j]<=l) x=j+1;
		  if(a[j]<r&&a[j+1]>r) y=j;
		}
		for(int j=x+1;j<=y;j++)
		{
			ans=j+ans-1;
		}long long p=1;
	//	cout<<ans<<endl;
		for(int j=1;j<=b;j++)
		{
			if((a[x]-p)>=l&&(a[x]-p!=1))
			{
			ans++;
			p=p*2;	
			//cout<<a[x]-p<<endl;
			}else break;
		}
	//	cout<<ans<<endl;
		 p=a[b-2]+1;
		// cout<<p<<endl;
		for(int j=1;j<=b;j++)
		{
			if((a[y+1]-p)<=r) ans++;
			p=p/2;
		}
		cout<<ans<<endl;
		ans=0;
}
}
}
