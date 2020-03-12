#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[1001],n,k;
int jie,ans;
int tiao(int da,int b)
{
	if(da>=n){ ans=min(ans,b);return b;}
	else for(int f=1;f<=a[da];f++)
         tiao(da+f,b+1);
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++)
   	cin>>a[i];
   	ans=500000;
   	for(int i=1;i<=a[1];i++)
   	{
	jie=tiao(i+1,1);
	   }
	 cout<<ans;
}


