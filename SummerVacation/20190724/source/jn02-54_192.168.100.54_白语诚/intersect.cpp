#include<bits/stdc++.h>
using namespace std;
long long xa,ya,num=1,s,xb,yb,n,l;
int dst[100001];
struct as
{
	int a,b;
}dstt[100001];
bool cmp(as a,as b)
{
	return a.a<b.a;
}
int main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>xa>>ya>>xb>>yb;
		dst[i]=xa*ya;
	}
	sort(dst+1,dst+n+1);
	for(int i=2;i<=n+1;i++)
	{
		if(dst[i]==dst[i-1])num++;
		else dstt[++s].a=num,dstt[s].b=dst[i-1],num=1;
	}
	sort(dstt+1,dstt+s+1,cmp);
	long long a=0,b=dstt[s].a,c=0;
	for(int i=s;dstt[i].a==b;i--)
	{
		if(abs(dstt[i].b)>abs(a))a=dstt[i].b;
		if(abs(dstt[i].b)==0)continue;
		if(abs(dstt[i].b)==abs(a)&&dstt[i].b<0)a=dstt[i].b;
	}
	cout<<a<<".00";
    return 0;
    }
