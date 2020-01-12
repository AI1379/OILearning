#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,l,r;
struct pe
{
	int a,b,c,k,p;
};
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		pe p[10000]={};
		l=1,r=3;
		p[1].a=1,p[1].b=1,p[1].c=1,p[1].k=1,p[1].p=1;
		p[2].a=1,p[2].b=2,p[2].c=0,p[2].k=1,p[2].p=2;
		p[3].a=2,p[3].b=1,p[3].c=0,p[3].k=1,p[3].p=3;
		while(l<=r)
		{
			if(p[l].a>=a&&p[l].b>=b&&p[l].c>=c)
			{
			cout<<p[l].k<<endl;
			break;
			}
			if(p[l].p==1)
			{
		p[++r].a=p[l].a+1,p[r].b=p[l].b+2,p[r].c=p[l].c,p[r].k=p[l].k+1,p[r].p=2;
        p[++r].a=p[l].a+2,p[r].b=p[l].b+1,p[r].c=p[l].c,p[r].k=p[l].k+1,p[r].p=3;			
		}
		if(p[l].p==2)
			{
		p[++r].a=p[l].a+1,p[r].b=p[l].b+1,p[r].c=p[l].c+1,p[r].k=p[l].k+1,p[r].p=1;
        p[++r].a=p[l].a+2,p[r].b=p[l].b+1,p[r].c=p[l].c,p[r].k=p[l].k+1,p[r].p=3;			
		}
		if(p[l].p==3)
			{
		p[++r].a=p[l].a+1,p[r].b=p[l].b+2,p[r].c=p[l].c,p[r].k=p[l].k+1,p[r].p=2;
        p[++r].a=p[l].a+1,p[r].b=p[l].b+1,p[r].c=p[l].c+1,p[r].k=p[l].k+1,p[r].p=1;			
		}
		l++;
		}
	}
	return 0;
}
