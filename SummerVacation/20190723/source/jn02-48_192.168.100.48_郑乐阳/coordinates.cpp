#include<bits/stdc++.h>
using namespace std;

int x,y,maxy=0,miny=0,maxx=0,minx=0,n;
bool Map[205][205];
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
		Map[x+100][y+100]=true;
	}
	//cout<<maxx<<" "<<maxy<<" "<<minx<<" "<<miny;	
	for(int i=maxy;i>=miny;i--)
	{
		for(int j=minx;j<=maxx;j++)
		{
			if(Map[j+100][i+100]==true)
			{
				printf("*");
			}
			else if(i==0&&j==0)
			{
				printf("+");
			}
			else if(i==0)
				printf("-");
			else if(j==0)
				printf("|");
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}

