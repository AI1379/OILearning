#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string s;int ans=0;
	cin>>s;
	int t=s.length();
	for(int i=0;i<=t;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
