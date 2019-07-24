#include<bits/stdc++.h>
using namespace std;
int n,k,x1[1000],y[1000],x2[1000],y2[1000];
int ans=0,lt=0,t;
jd(int a,int b,int c,int d)
{
	if(a*b==k||c*d==k)return 1;
	else if(a+c==b+d)
	{
		if(a*c==k)return 1;
	}
	else if(a-c==b-d)
	return 0;
}
int main()
{
	cin >>n;
	for(int i=1;i<=n;i++) cin>>x1[i]>>y[i]>>x2[i]>>y2[i];
	for(double k=-100;k<=100;k=k+0.01)
	{
		t=0;
		for(int j=1;j<=n;j++)
		    if(jd(x1[j],y[j],x2[j],y2[j])==1) t++;
		if(t>lt)lt=t,ans=k;
	}
	cout<<ans;
	return 0;
}
