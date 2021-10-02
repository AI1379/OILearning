#include<bits/stdc++.h>
using namespace std;
const int maxn=300;
const int mid=150;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
bool flag[maxn][maxn];
int n,aa,bb;
int firstx=mid,firsty=mid,endx=mid,endy=mid;
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(aa), read(bb), aa+=mid, bb+=mid,
		flag[aa][bb]=1,
		firstx=min(firstx,aa),
		firsty=min(firsty,bb),
		endx=max(endx,aa),
		endy=max(endy,bb);
	for(int i=endy;i>=firsty;i--,printf("\n"))
		for(int j=firstx;j<=endx;j++)
		{
			if(flag[j][i]) { printf("*"); continue; }
			if(j==mid&&i==mid) { printf("+"); continue; }
			if(j==mid&&i!=mid) { printf("|"); continue; } 
			if(j!=mid&&i==mid) { printf("-"); continue; }
			printf(".");
		}
	return 0;
}
