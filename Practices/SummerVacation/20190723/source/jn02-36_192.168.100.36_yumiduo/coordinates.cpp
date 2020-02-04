#include<bits/stdc++.h>
using namespace std;
int n,x[301],y[301],maxx,maxy,minx=0x7f7f7f7f,miny=0x7f7f7f7f;
bool flag;
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",x+i,y+i);
		maxx=max(maxx,x[i]);
		maxy=max(maxy,y[i]);
		minx=min(minx,x[i]);
		miny=min(miny,y[i]);
	}
	minx=min(minx,0);
	miny=min(miny,0);
	for(int j=maxy;j>=miny;j--)
	{
		for(int i=minx;i<=maxx;i++)
		{
			flag=false;
			for(int k=1;k<=n;k++)
			{
				if(x[k]==i&&y[k]==j&&flag==false)
				printf("*"),flag=true;
			}
			if(flag==false)
			{
				if(i==0&&j==0)
				printf("+");
				else if(i==0&&j!=0)
				printf("|");
				else if(i!=0&&j==0)
				printf("-");
				else
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
