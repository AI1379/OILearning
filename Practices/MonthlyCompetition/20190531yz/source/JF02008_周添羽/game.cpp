#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[101][101],n,b,c,k,x,y,v,p,ans;
char f;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>p;
	for(int i=1;i<=p;i++)
	{
	cin>>x>>y>>v>>f;
	a[x][y]=v;
	
	if(f=='L')
	{
		for(int k=4;k>=1;k--)
		for(int q=4;q>=1;q--)
	{
		for(int i=4;i>=1;i--)
		for(int j=4;j>=1;j--)
		{  int n=j;
				while(a[i][n-1]==0&&a[i][n]!=0&&n>1)
			    {
			     a[i][n-1]=a[i][n];
			     a[i][n]=0;
			     n--;
			      }
		}
		if(a[k][q]!=0&&a[k][q]==a[k][q+1])a[k][q]+=a[k][q],a[k][q+1]=0;
		}
		for(int i=4;i>=1;i--)
		for(int j=4;j>=1;j--)
		{  int n=j;
				while(a[i][n-1]==0&&a[i][n]!=0&&n>1)
			    {
			     a[i][n-1]=a[i][n];
			     a[i][n]=0;
			     n--;
			      }
		}
//	for(int i=1;i<=4;i++)
//	{for(int j=1;j<=4;j++)
//	cout<<a[i][j];
//	cout<<endl;
//	}
	}
	if(f=='R')
	{
		for(int k=4;k>=1;k--)
		for(int q=4;q>=1;q--)
	{
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{  int n=j;
				while(a[i][n+1]==0&&a[i][n]!=0&&n<4)
			    {
			     a[i][n+1]=a[i][n];
			     a[i][n]=0;
			     n++;
			      }
		}
		if(a[k][q]!=0&&a[k][q]==a[k][q+1])a[k][q]+=a[k][q],a[k][q+1]=0;
		}
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{  int n=j;
				while(a[i][n+1]==0&&a[i][n]!=0&&n<4)
			    {
			     a[i][n+1]=a[i][n];
			     a[i][n]=0;
			     n++;
			      }
		}
//	for(int i=1;i<=4;i++)
//	{for(int j=1;j<=4;j++)
//	cout<<a[i][j];
//	cout<<endl;
//	}
	}
	if(f=='U')
	{
		for(int k=4;k>=1;k--)
		for(int q=4;q>=1;q--)
	{
		for(int j=4;j>=1;j--)
		for(int i=4;i>=1;i--)
		{  int n=i;
				while(a[n-1][j]==0&&a[n][j]!=0&&n>1)
			    {
			     a[n-1][j]=a[n][j];
			     a[n][j]=0;
			     n--;
			      }
		}
		if(a[k][q]!=0&&a[k][q]==a[k+1][q])a[k][q]+=a[k][q],a[k+1][q]=0;
		}
		for(int j=4;j>=1;j--)
		for(int i=4;i>=1;i--)
		{  int n=i;
				while(a[n-1][j]==0&&a[n][j]!=0&&n>1)
			    {
			     a[n-1][j]=a[n][j];
			     a[n][j]=0;
			     n--;
			      }
		}
//	for(int i=1;i<=4;i++)
//	{for(int j=1;j<=4;j++)
//	cout<<a[i][j];
//	cout<<endl;
//	}
	}
	if(f=='D')
	{
		for(int k=4;k>=1;k--)
		for(int q=4;q>=1;q--)
	{
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{  int n=i;
				while(a[n+1][j]==0&&a[n][j]!=0&&n<4)
			    {
			     a[n+1][j]=a[n][j];
			     a[n][j]=0;
			     n++;
			      }
		}
		if(a[k][q]!=0&&a[k][q]==a[k+1][q])a[k][q]+=a[k][q],a[k+1][q]=0;
		}
			for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{  int n=i;
				while(a[n+1][j]==0&&a[n][j]!=0&&n<4)
			    {
			     a[n+1][j]=a[n][j];
			     a[n][j]=0;
			     n++;
			      }
		}
//	for(int i=1;i<=4;i++)
//	{for(int j=1;j<=4;j++)
//	cout<<a[i][j];
//	cout<<endl;
//	}
	}
	}
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
	if(a[i][j]==0)ans++;
	if(ans==0){cout<<"Game over!";return 0;}
	
    for(int i=1;i<=4;i++)
	{for(int j=1;j<=4;j++)
	cout<<a[i][j]<<" ";
	cout<<endl;
	}
}


