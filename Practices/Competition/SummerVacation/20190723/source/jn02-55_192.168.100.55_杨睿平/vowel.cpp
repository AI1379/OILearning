#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	int i,j,n=s.size();
	for(i=0;i<n;i++){
		if(tolower(s[i])=='a'||tolower(s[i])=='e'||tolower(s[i])=='i'||tolower(s[i])=='o'||tolower(s[i])=='u'){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
