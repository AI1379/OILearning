#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,ans,cnt,ma[10][10],d[5];
char ch;
void print()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		cout<<ma[i][j]<<" ";
		cout<<endl;
	}
}
void gan()
{
	for(int j=1;j<=4;j++)
	{
		cnt=0;
		for(int k=1;k<=4;k++)
		{
			if(ma[j][k]==0)
			{
				for(int q=k;q<=4;q++)
				ma[j][q]=ma[j][q+1];
				k--,cnt++;
			}
			if(cnt>8)
			break;
		}
		for(int k=1;k<=3;k++)
		{				
			if(ma[j][k]!=0&&ma[j][k+1]==ma[j][k])
			{
				ma[j][k]*=2;
				for(int q=k+1;q<=4;q++)
				ma[j][q]=ma[j][q+1];
			}
		}
	}
}
void around()
{
	int bei[10][10];
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		bei[i][j]=ma[i][j];
	}
	ma[1][1]=bei[4][1];
	ma[1][2]=bei[3][1];
	ma[1][3]=bei[2][1];
	ma[1][4]=bei[1][1];
	ma[2][1]=bei[4][2];
	ma[2][2]=bei[3][2];
	ma[2][3]=bei[2][2];
	ma[2][4]=bei[1][2];
	ma[3][1]=bei[4][3];
	ma[3][2]=bei[3][3];
	ma[3][3]=bei[2][3];
	ma[3][4]=bei[1][3];
	ma[4][1]=bei[4][4];
	ma[4][2]=bei[3][4];
	ma[4][3]=bei[2][4];
	ma[4][4]=bei[1][4];
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		getchar();
		ch=getchar();
		ma[a][b]=c;
		ans=0;
		for(int j=1;j<=4;j++)
		{
			for(int k=1;k<=4;k++)
			{
				if(ma[j][k]!=0)
				ans++;
			}
		}
		if(ans==16)
		{
			cout<<"Game over!";
			return 0;
		}
		if(ch=='L')
		gan();
		if(ch=='R')
		around(),around(),gan(),around(),around();
		if(ch=='U')
		around(),around(),around(),gan(),around();
		if(ch=='D')
		around(),gan(),around(),around(),around();
	}
	print();
	return 0;
}
