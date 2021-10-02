#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string s;
	cin >> s;
	s = " " + s;
	int ssize = s.size();
	
	char tmp;
	int ans = 0;
	for(int i = 1;i < ssize;i++){
		tmp = s[i];
		if(tmp == 'a') ans++;
		if(tmp == 'e') ans++;
		if(tmp == 'i') ans++;
		if(tmp == 'o') ans++;
		if(tmp == 'u') ans++;
		if(tmp == 'A') ans++;
		if(tmp == 'E') ans++;
		if(tmp == 'I') ans++;
		if(tmp == 'O') ans++;
		if(tmp == 'U') ans++;
	}
	cout << ans;
}
