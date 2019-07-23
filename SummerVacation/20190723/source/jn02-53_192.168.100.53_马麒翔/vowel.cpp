#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string a;
	long long ans=0;
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}

