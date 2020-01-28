#include<bits/stdc++.h>
using namespace std;
string s;
int l,ans;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
	  if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
	}
	for(int i=0;i<l;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') ans++;
	}
	cout<<ans<<endl;
	return 0;
}
