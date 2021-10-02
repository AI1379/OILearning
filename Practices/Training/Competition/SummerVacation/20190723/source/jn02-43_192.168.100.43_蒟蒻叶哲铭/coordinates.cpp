#include<bits/stdc++.h>
using namespace std;
int n,x,y,xz=100,xy=100,ys=100,yx=100;
bool b[202][202];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		x+=100;y+=100;
		xz=min(x,xz);
		xy=max(xy,x);
		ys=max(ys,y);
		yx=min(yx,y);
		b[x][y]=true;
	}
	for(int i=ys;i>=yx;--i)
	{
		for(int j=xz;j<=xy;++j)
		{
			if(b[j][i]==true)printf("*");
			else if(i==100&&j==100)printf("+");
			else if(i==100)printf("-");
			else if(j==100)printf("|");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}
