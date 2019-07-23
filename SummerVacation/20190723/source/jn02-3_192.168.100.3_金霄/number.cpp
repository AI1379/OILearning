#include<bits/stdc++.h>
using namespace std;

long long T,m,n,rest,s[301],total=0,k;

void pd(int d)
{
	if(d<=n)
	{	
		total++;
		total=total%100000007;
	}

}

void dfs(int dep)
{
	if(rest==0)pd(dep-1);
	else
	{
		for(int i=s[dep-1];i<=rest;i++)
		{
			s[dep]=i;
			rest-=i;
			dfs(dep+1);
			rest+=i;
		}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>m>>n;
		s[0]=1;
		rest=m;
		dfs(1);
		cout<<total<<endl;
		total=0;
		k=0;
	}
	return 0;
}
