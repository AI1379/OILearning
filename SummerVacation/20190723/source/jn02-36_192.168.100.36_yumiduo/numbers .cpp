#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans=0;
const int mo=100000007;
void search(int k,int last,int rest)
{
	if(k>n||rest>m)
	return;
	for(int i=last;i+rest<=m;i++)
	{
		if(k==n&&i+rest==m)
		ans=(ans+1)%mo;
		else
		search(k+1,i,rest+i);
	}
}
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&m,&n);
		search(1,0,0);
		printf("%d\n",ans);
	}
	return 0;
}/*
0 0 0 0 1 1 1
0 0 0 0 0 2 1
0 0 0 0 0 0 3




*/
