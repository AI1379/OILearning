#include<bits/stdc++.h>
using namespace std;
map<long long,int>mp;
int jud2(long long l){
	int ws = 0;
	while(l){
		l /= 2;
		ws++;
	}
	return ws;
}
long long q_pow(long long x,long long y){
	long long base = x,ans = 1;
	while(y){
		if(y % 2) ans *= base;
		base *= base;
		y /= 2;
	}
	return ans;
}
long long zhl(int x){
	x--;
	long long ans = 0;
	for(int i = 1;i <= x;i++){
		ans = ans * 2 + 1;
	}
	return ans;
}
int main(){
	long long l,r,l1,r1;
	int t,wsl,wsr;
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> l >> r;
		wsl = jud2(l);
		wsr = jud2(r);
		l1 = zhl(wsl);
		//r1 = zhr(wsr);
	}
	cout << l1;
}
