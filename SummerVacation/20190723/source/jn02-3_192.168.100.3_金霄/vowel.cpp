#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size()-1,ans=0;
	for(int i=0;i<=len;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		s[i]=tolower(s[i]);
	}
	for(int i=0;i<=len;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
		ans++;
	}
	cout<<ans;
	return 0;
}
