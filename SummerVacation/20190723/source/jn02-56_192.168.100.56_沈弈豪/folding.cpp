#include<bits/stdc++.h>
using namespace std;
int ans,a,b,x,y;
int pd(int m,int n)
{
	ans=0;
	while(m<n)
	{
		m*=2;
		ans++;
	}
//	cout<<m<<" "<<n<<endl;
	return ans;
}
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(max(a,b)<max(x,y)||min(a,b)<min(x,y))
	{
		cout<<"-1";
		return 0;
	}
	cout<<min(pd(x,a)+pd(y,b),pd(x,b)+pd(y,a));
	return 0;
}
