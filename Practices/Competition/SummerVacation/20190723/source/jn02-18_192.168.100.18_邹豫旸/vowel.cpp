#include<bits/stdc++.h>
using namespace std;
string s; int sl,ans;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	sl=s.size();
	for(int i=0; i<sl; i++){
		s[i]=tolower(s[i]); 
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') ans++;
	}
	printf("%d",ans);
	return 0;
}
