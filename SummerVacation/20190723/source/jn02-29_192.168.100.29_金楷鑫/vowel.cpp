#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("vowel.in","r",stdin);
  freopen("vowel.out","w",stdout);
  string s;
  int x,y,z,a,b,c,ans=0;
  cin>>s;
  x=s.size();
  for(int i=0;i<x;i++)
  {
    if(s[i]=='a') ans++;
	if(s[i]=='e') ans++;
	if(s[i]=='i') ans++;
	if(s[i]=='o') ans++;
	if(s[i]=='u') ans++;
	if(s[i]=='A') ans++;
	if(s[i]=='E') ans++;
	if(s[i]=='I') ans++;
	if(s[i]=='O') ans++;
	if(s[i]=='U') ans++;	
  }	
  cout<<ans;
}
