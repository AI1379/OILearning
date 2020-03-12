#include<bits/stdc++.h>
using namespace std;
int h,w,m,mapp[501][501],ans;
int dx[5]{0,0,1,0,-1};
int dy[5]{0,1,0,-1,0};
bool f=true,r[501][501],dr[501][501];
bool om(int x,int y)
{
	if (x>h || y>w || x<1 || y<1)
		return true;
	else
		return false;
}
void bfs(int xx,int yy)
{
	memset(dr,false,sizeof(dr));
	queue<int>X;
	queue<int>Y;
	X.push(xx);
	Y.push(yy);
	while (!X.empty())
	{
		r[X.front()][Y.front()]=true;
		if (dr[X.front()][Y.front()])
		{
			X.pop();
			Y.pop();
			continue;
		}
		dr[X.front()][Y.front()]=true;
		for (int i=1;i<=4;i++)
		{
			int x=X.front()+dx[i];
			int y=Y.front()+dy[i];
			if (om(x,y) || dr[x][y] ||abs(mapp[x][y]-mapp[X.front()][Y.front()])>m)
				continue;
			X.push(x);
			Y.push(y);
		}
		X.pop();
		Y.pop();
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&h,&w,&m);
	for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++)
			scanf("%d",&mapp[i][j]);
	while(f)
	{
		bool F=true;
		int ii,jj;
		for (ii=1;ii<=h && F;ii++)
			for (jj=1;jj<=w && F;jj++)
				if (!r[ii][jj])
				{
					bfs(ii,jj);
					F=false;
					break;
				}
		if (F)
			f=false;
		ans++;
	}
	printf("%d",ans-1);
	return 0;
}
