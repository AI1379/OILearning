#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack> 
#include <ctime>

using namespace std;

int n,m;
int a[20][20];
int h[20],l[20];
bool use[20][20];
int tot=0,ans=0;

void dfs(int xx,int yy)
{
	tot+=a[xx][yy];
	++h[xx]; ++l[yy];
	use[xx][yy]=false;
	if(tot>ans)ans=tot;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(use[i][j]&&h[i]<2&&l[j]<2)
				dfs(i,j);
	use[xx][yy]=true;
	tot-=a[xx][yy];
	--h[xx]; --l[yy];
	return;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	memset(h,0,sizeof(h));
	memset(l,0,sizeof(l));
	memset(use,true,sizeof(use));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			dfs(i,j);
	printf("%d\n",ans);
	return 0;
}
