#include<bits/stdc++.h>
using namespace std;
int n,x,y,minx=2e9,miny=2e9,maxx=-2e9,maxy=-2e9;
bool mapp[300][300];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		maxx=max(maxx,x);
		minx=min(minx,x);
		maxy=max(maxy,y);
		miny=min(miny,y);
		mapp[x+150][y+150]=true;
	}
	if (maxx<0)
		maxx=0;
	if (minx>0)
		minx=0;
	if (maxy<0)
		maxy=0;
	if (miny>0)
		miny=0;
	for (int i=maxy;i>=miny;i--)
	{
		for (int j=minx;j<=maxx;j++)
		{
			if (mapp[j+150][i+150])
			{
				printf("*");
				continue;
			}
			if (i==0 && j==0)	
			{
				printf("+");
				continue;
			}
			if (i==0)
			{
				printf("-");
				continue;
			}
			if (j==0)
			{
				printf("|");
				continue;
			}
				printf(".");
		}
		printf("\n");
	}
	return 0;
}
