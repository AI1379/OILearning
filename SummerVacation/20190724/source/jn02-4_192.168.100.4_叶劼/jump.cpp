#include<bits/stdc++.h>
using namespace std;
int H,W,M,h[501][501],ans=1;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>H>>W>>M;
	for(int i=1;i<=H;i++)
	    for(int j=1;j<=W;j++)
	        cin>>h[i][j];
	for(int i=2;i<=W;i++)
	{
		int a=abs(h[1][i-1]-h[1][i]);
	    if(abs(a)>M)
	    	ans++;
	}
	for(int i=2;i<=H;i++)
	{
		int a=abs(h[i-1][1]-h[i-1][1]);
	    if(abs(a)>M)
	    	ans++;
	}
	for(int i=2;i<=H;i++)
	    for(int j=2;j<=W;j++)
	    {
	    	int a=min(abs(h[i-1][j]-h[i][j]),abs(h[i][j-1]-h[i][j]));
	    	if(abs(a)>M)
	    	    ans++;
		}
	cout<<ans;
	return 0;
}
