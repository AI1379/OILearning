#include<bits/stdc++.h>
using namespace std;

int n,x,y,v,a[5][5];
char f;

void c_U();
void c_D();
void c_L();
void c_R();

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>x>>y>>v>>f;
		if(a[x][y]!=0)
		{
			cout<<"Game over!";
			return 0;
		}
		a[x][y]=v;
		if(f=='U') c_U();
		else if(f=='D') c_D();
		else if(f=='L') c_L();
		else if(f=='R') c_R();
	}
	int k=1;
	for(int i=1 ; i<=4 ; i++)
	{
		for(int j=1 ; j<=4 ; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;//T3
}

void c_U()
{
	for(int j=1 ; j<=4 ; j++)
	{
		if(a[3][j]==0) a[3][j]=a[4][j],a[4][j]=0;
		if(a[2][j]==0) a[2][j]=a[3][j],a[3][j]=a[4][j],a[4][j]=0;
		if(a[1][j]==0) a[1][j]=a[2][j],a[2][j]=a[3][j],a[3][j]=a[4][j],a[4][j]=0;
		if(a[1][j]==0||a[2][j]==0) continue;
		if(a[1][j]==a[2][j])
		{
			a[1][j]+=a[2][j];a[2][j]=a[3][j];a[3][j]=a[4][j];a[4][j]=0;
			if(a[2][j]==a[3][j]) a[2][j]+=a[3][j],a[3][j]=0;
		}
		if(a[3][j]==0) continue;
		if(a[2][j]==a[3][j]) a[2][j]+=a[3][j],a[3][j]=a[4][j],a[4][j]=0;
		if(a[3][j]==a[4][j]) a[3][j]+=a[4][j],a[4][j]=0;
	}
	return;
}

void c_D()
{
	for(int j=1 ; j<=4 ; j++)
	{
		if(a[2][j]==0) a[2][j]=a[1][j],a[1][j]=0;
		if(a[3][j]==0) a[3][j]=a[2][j],a[2][j]=a[1][j],a[1][j]=0;
		if(a[4][j]==0) a[4][j]=a[3][j],a[3][j]=a[2][j],a[2][j]=a[1][j],a[1][j]=0;
		if(a[4][j]==0||a[3][j]==0) continue;
		if(a[4][j]==a[3][j])
		{
			a[4][j]+=a[3][j];a[3][j]=a[2][j];a[2][j]=a[1][j];a[1][j]=0;
			if(a[3][j]==a[2][j]) a[3][j]+=a[2][j],a[2][j]=0;
		}
		if(a[2][j]==0) continue;
		if(a[3][j]==a[2][j]) a[3][j]+=a[2][j],a[2][j]=a[1][j],a[1][j]=0;
		if(a[2][j]==a[1][j]) a[2][j]+=a[1][j],a[1][j]=0;
	}
	return;
}

void c_L()
{
	for(int i=1 ; i<=4 ; i++)
	{
		if(a[i][3]==0) a[i][3]=a[i][4],a[i][4]=0;
		if(a[i][2]==0) a[i][2]=a[i][3],a[i][3]=a[i][4],a[i][4]=0;
		if(a[i][1]==0) a[i][1]=a[i][2],a[i][2]=a[i][3],a[i][3]=a[i][4],a[i][4]=0;
		if(a[i][1]==0||a[i][2]==0) continue;
		if(a[i][1]==a[i][2])
		{
			a[i][1]+=a[i][2];a[i][2]=a[i][3];a[i][3]=a[i][4];a[i][4]=0;
			if(a[i][2]==a[i][3]) a[i][2]+=a[i][3],a[i][3]=0;
		}
		if(a[i][3]==0) continue;
		if(a[i][2]==a[i][3]) a[i][2]+=a[i][3],a[i][3]=a[i][4],a[i][4]=0;
		if(a[i][3]==a[i][4]) a[i][3]+=a[i][4],a[i][4]=0;
	}
	return;
}

void c_R()
{
	for(int i=1 ; i<=4 ; i++)
	{
		if(a[i][2]==0) a[i][2]=a[i][1],a[i][1]=0;
		if(a[i][3]==0) a[i][3]=a[i][2],a[i][2]=a[i][1],a[i][1]=0;
		if(a[i][4]==0) a[i][4]=a[i][3],a[i][3]=a[i][2],a[i][2]=a[i][1],a[i][1]=0;
		if(a[i][4]==0||a[i][3]==0) continue;
		if(a[i][4]==a[i][3])
		{
			a[i][4]+=a[i][3];a[i][3]=a[i][2];a[i][2]=a[i][1];a[i][1]=0;
			if(a[i][3]==a[i][2]) a[i][3]+=a[i][2],a[i][2]=0;
		}
		if(a[i][2]==0) continue;
		if(a[i][3]==a[i][2]) a[i][3]+=a[i][2],a[i][2]=a[i][1],a[i][1]=0;
		if(a[i][2]==a[i][1]) a[i][2]+=a[i][1],a[i][1]=0;
	}
	return;
}
