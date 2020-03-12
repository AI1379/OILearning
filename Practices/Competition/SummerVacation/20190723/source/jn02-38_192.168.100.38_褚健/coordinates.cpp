#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int map[500][500];
int x,y,n,maxx,minx,miny,maxy;

int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
	{
		scanf("%d%d",&x,&y);
		if(x>maxx) maxx=x;
		if(x<minx) minx=x;
		if(y>maxy) maxy=y;
		if(y<miny) miny=y;
		map[x+100][y+100]=1;
	}
	for(int j=maxy+100;j>=miny+100;j--)
	{
		for(int i=minx+100;i<=maxx+100;i++)
		{	
			if(map[i][j]==1) printf("*");
			else if(i==100&&j==100) printf("+");
			else if(i==100) printf("|");
			else if(j==100) printf("-");
			else printf(".");
		}
		printf("\n");
	}
}
