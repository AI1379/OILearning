#include<bits/stdc++.h>
using namespace std;

char s[300][300];

struct dian{
	int x,y;
}d[251],e[251];

bool cmp1(dian p,dian q)
{
	if(p.x<q.x)return 1;
	if(p.x>q.x)return 0;
}

bool cmp2(dian p,dian q)
{
	if(p.y<q.y)return 1;
	if(p.y>q.y)return 0;
	
}
int main()
{
	
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i].x>>d[i].y;
		e[i].x=d[i].x;
		e[i].y=d[i].y;
		
	}
	sort(d+1,d+n+1,cmp1);
	sort(e+1,e+n+1,cmp2);
	int xmi=min(0,d[1].x),ymi=min(0,e[1].y);
	int xma=max(0,d[n].x),yma=max(0,e[n].y);
	int yz=xma-xmi+1,xz=yma-ymi+1;	
	
	for(int i=1;i<=300;i++)
	{
		s[150][i]='|';
		s[i][150]='-';
	}
	for(int i=1;i<=n;i++)
		s[150+d[i].x][150+d[i].y]='*';
	s[150][150]='+';
	for(int i=150+xmi;i<=150+xma;i++)
	{
		for(int j=150+ymi;j<=150+yma;j++)
		{
			if(s[i][j]!='+'&&s[i][j]!='*'&&s[i][j]!='|'&&s[i][j]!='-')
			s[i][j]='.';
		}
	}
	for(int j=150+yma;j>=150+ymi;j--)
	{
			for(int i=150+xmi;i<=150+xma;i++)
		{
			cout<<s[i][j];	
		}
		cout<<endl;
	}
	return 0;
}
