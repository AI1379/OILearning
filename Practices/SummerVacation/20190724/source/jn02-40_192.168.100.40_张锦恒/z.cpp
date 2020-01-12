#include <bits/stdc++.h>
#define LoL long long
using namespace std;

struct Num
{
	int v,c,a;
}xz[201];

int n,m,k,w[201],c[201],a[201],f[2][100001];

bool cmp(Num x,Num y)
{
	return x.v/1.0/x.c>y.v/1.0/y.c;
}

int isis(int v,int yq)
{
	int p=0,ans;
	memset(f,0,sizeof(f));
	for(int i=1 ; i<=n ; i++)
	{
		p^=1;
		memset(f[p],0,sizeof(f[p]));
		for(int j=0 ; j<=v ; j++)
		{
			for(int k=0 ; k<=a[i] ; k++)
				if(j>=c[i]*k)
					f[p][j]=max(f[p][j],max(f[p^1][j],f[p^1][j-c[i]*k]+w[i]*k));
				else
					f[p][j]=max(f[p][j],f[p^1][j]);
		}
	}
	for(int i=1 ; i<=v ; i++)
		if(f[p][i]>=yq)
		{
			ans=i;
			break;
		}
	cout<<ans<<endl;
	return ans;
}

int main()
{
	int p,v;
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	cin>>n>>m>>p>>k;
	for(int i=1 ; i<=n ; i++)
		cin>>w[i]>>c[i]>>a[i];
	v=isis(p*1.5,p);
	for(int i=1 ; i<=m ; i++)
		cin>>xz[i].v>>xz[i].c>>xz[i].a;
	sort(xz+1,xz+m+1,cmp);
	int jg=0;
	for(int i=1 ; i<=m ; i++)
		for(int j=1 ; j<=xz[i].a ; j++)
		{
			jg+=xz[i].c;
			v-=xz[i].v;
			if(jg>k)
			{
				cout<<"FAIL";
				return 0;
			}
			if(v<=0)
			{
				cout<<jg;
				return 0;
			}
		}
	cout<<jg;
	return 0;
}
/*
5 3 34 34
1 4 1
9 4 2
5 3 3
1 3 3
5 3 2
2000000
50000


3 4 5
6 7 5
5 3 8
*/
