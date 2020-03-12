#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	
	long long W,w,H,h;
	cin >> W >> H >> w >> h;
	if(W < H) swap(W,H);
	if(w < h) swap(w,h);
	
	if(w > W || h > H){
		cout << -1;
		return 0;
	}
	
	long long nw = 0;
	while(w < W){
		nw++;
		W /= 2;
	}
	long long nh = 0;
	while(h < H){
		nh++;
		H /= 2;
	}
	
	long long ans = nh + nw;
	cout << ans;
}
