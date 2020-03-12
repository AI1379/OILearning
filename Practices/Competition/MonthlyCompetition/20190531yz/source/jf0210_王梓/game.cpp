#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	int s=0,t=1; char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') t=-1; c=getchar(); }
	while(c>='0'&&c<='9') { s=s*10+c-'0'; c=getchar(); }
	x=s*t; return ;
}
int n;
int a[10][10];
int b[10][10];
int x,y,v,f;
char c;
bool flag=0;
void cop()
{
	bool fl=1;
	memset(a,0,sizeof(a));
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			a[i][j]=b[i][j];
			if(b[i][j]==0) fl=0;
		}
	memset(b,0,sizeof(b));
	if(fl) flag=1;
	return ;
}

void output()
{
	for(int i=1;i<=4;i++,cout<<endl)
		for(int j=1;j<=4;j++)
			cout<<a[i][j]<<" ";
	cout<<endl<<endl;
}

void outputb()
{
	for(int i=1;i<=4;i++,cout<<endl)
		for(int j=1;j<=4;j++)
			cout<<b[i][j]<<" ";
	cout<<endl<<endl;
}


void up()
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			int xx=i;
			while(b[xx-1][j]==0&&xx>1) xx--;
			b[xx][j]=a[i][j];
			if(b[xx][j]==b[xx-1][j]&&xx>1)
				b[xx-1][j]*=2,b[xx][j]=0;
		}
	cop();
}

void down()
{
	for(int i=4;i>=1;i--)
		for(int j=1;j<=4;j++)
		{
			int xx=i;
			while(b[xx+1][j]==0&&xx<4) xx++;
			b[xx][j]=a[i][j];
			if(b[xx][j]==b[xx+1][j]&&xx<4)
				b[xx+1][j]*=2,b[xx][j]=0;
		}
	cop();
}

void rig()
{
	for(int i=1;i<=4;i++)
		for(int j=4;j>=1;j--)
		{
			int xx=j;
			while(b[i][xx+1]==0&&xx<4) xx++;
			b[i][xx]=a[i][j];
			if(b[i][xx]==b[i][xx+1]&&xx<4)
				b[i][xx+1]*=2,b[i][xx]=0;
		}
	cop();
}

void lef()
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			int xx=j;
			while(b[i][xx-1]==0&&xx>1) xx--;
			b[i][xx]=a[i][j];
			if(b[i][xx]==b[i][xx-1]&&xx>1)
				b[i][xx-1]*=2,b[i][xx]=0;
		}
	cop();
}

void cz()
{
	if(c=='L') lef();
	if(c=='R') rig();
	if(c=='D') down();
	if(c=='U') up();
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(x),read(y),read(v); cin>>c;
		a[x][y]=v;
		cz();
		if(flag)
		{
			cout<<"Game over!"<<endl;
			return 0;
		}
	}
	output();
	return 0;
}

/*
8
1 3 4 L
2 3 2 U
2 4 2 R
4 1 2 L
3 4 2 L
3 2 2 D
1 3 4 R
1 3 2 U

*/
