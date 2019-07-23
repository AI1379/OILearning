#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	int sum=0,len;
	string s;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
		sum++;
	}
	cout<<sum<<endl;
	return 0;
}
