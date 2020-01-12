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

char sinn[100],sout[100],in[100],out[100];
int T;
long long DataN[10]={10,1000,3000,5000,10000,10000,10000,10000,10000,10000};
void files()
{
	memset(sinn,0,sizeof(sinn));
	memset(sout,0,sizeof(sout));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	strcat(sinn,"History");
	strcat(sout,"History");
	sprintf(sinn+strlen(sinn),"%d.",T);
	sprintf(sout+strlen(sout),"%d.",T);
	strcat(in,sinn),strcat(in,"in");
	strcat(out,sout),strcat(out,"ans");
}

bool datause[5010][5010];

void MakeData()
{
	memset(datause,true,sizeof(datause));
	int n=DataN[T],m=30000;
	int DATAMAX=n/2;
	int x,y;
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
	{
		x=rand()%DATAMAX+1;
		y=rand()%DATAMAX+1;
		while(!datause[x][y])
		{
			x=rand()%DATAMAX+1;
			y=rand()%DATAMAX+1;
		}
		datause[x][y]=false;
		printf("%d %d\n",x,y);
	}
	printf("%d\n",m);
	for(int i=1;i<=m;++i)printf("%d ",(i-1)%(DATAMAX+rand()%2)+1);
	printf("\n");
	return;
}

#define MAXN 5010

int n,m;
int x,y;
int son[MAXN][MAXN];
bool isuse[MAXN];
int ans[MAXN];
int now;
queue <int> q;

void Main()
{
	memset(son,0,sizeof(son));
	memset(ans,0,sizeof(ans));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		son[x][++son[x][0]]=y;
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=5000;++i)
	{
		memset(isuse,true,sizeof(isuse));
		isuse[i]=false;
		q.push(i);
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			for(int j=1;j<=son[now][0];++j)
				if(isuse[son[now][j]])
				{
					isuse[son[now][j]]=false;
					++ans[i];
					q.push(son[now][j]);
				}
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		if(x>5000)printf("0 0\n");
			else printf("%d %d\n",son[x][0],ans[x]);
	}
	return;
}

int main()
{
	srand((unsigned)time(0));
	for(T=0;T<10;T++)
	{
		files();
		freopen(in,"w",stdout);
		MakeData();
		fclose(stdout);
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		Main();
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
