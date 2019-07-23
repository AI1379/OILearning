#include<bits/stdc++.h>
using namespace std;
int t,b[100001];
int zdgys(int t1,int t2)
{
	int r;
	while(r)
	{
		r=t1%t2;
		t1=t2;
		t2=r;
	}
	return t1;
}
int zxgbs(int t1,int t2)
{
	return t1*t2/zdgys(t1,t2);
}
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int m,h1,h2,a1,a2,x1,y1,x2,y2,s1=0,s2=0;
		cin>>m;
		cin>>h1>>a1;
		cin>>x1>>y1;
		for(int i=0;i<=m;i++)
		    b[i]=0;
		while(1)
		{
			if(h1==a1)
			    break;
			if(b[h1])
			{
				s1=-1;
				break;
			}
			b[h1]=1;
			h1=(x1*h1+y1)%m;
			s1++;
		}
		for(int i=0;i<=m;i++)
		    b[i]=0;
		cin>>h2>>a2;
		cin>>x2>>y2;
		while(1)
		{
			if(h2==a2)
			    break;
			if(b[h2])
			{
				s2=-1;
				break;
			}
			b[h2]=1;
			h2=(x2*h2+y2)%m;
			s2++;
		};
		if(s1>=0 && s2>=0)
		    cout<<zxgbs(s1,s2)<<endl;
		else
		    cout<<-1<<endl;
	}
	return 0;
}
