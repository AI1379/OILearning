#include<bits/stdc++.h>
using namespace std;
long long t,l,r,ret=1,x=1,y=1,ans,l1,r1;
bool jz(long long x){
	int a[100000];
	int n=0,flag=0;
	long long l;
	do{
		a[++n]=x%2;
		if(a[n]==0&&!flag) flag=1; 
		else if(a[n]==0&&flag) return 0;
		x/=2;
	}while(x!=0);
	if(flag) return 1;
	else return 0;
}
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
    cin>>t;
	for(int i=1;i<=t;i++)
	{    ans=0;
		cin>>l>>r;
	    for(long long j=l;j<=r;j++)
	    {
	    	if(jz(j)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
