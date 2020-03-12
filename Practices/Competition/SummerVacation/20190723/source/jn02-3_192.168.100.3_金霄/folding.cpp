#include<bits/stdc++.h>
using namespace std;

int b[3],s[3];
unsigned long long ans=0;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>b[1]>>b[2]>>s[1]>>s[2];
	sort(b+1,b+2);
	sort(s+1,s+2);
	if(s[1]>b[1]||s[2]>b[2])
	{
		cout<<-1;
		return 0;
	}
	while(s[2]<b[2])
	{
		ans++;
		b[2]/=2;
	}
	while(s[1]<b[1])
	{
		ans++;
		b[1]/=2;
	}
	cout<<ans;
	return 0;
}
