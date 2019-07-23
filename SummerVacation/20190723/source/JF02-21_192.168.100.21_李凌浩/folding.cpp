#include<bits/stdc++.h>
using namespace std;
int W,H,w,h,ans1,ans2;
int an(int a,int b) {
	int ans=0;
	for(; a>b; a=(a%2==0?a/2:a/2+1)) ans++;
	a=(a+1)/2;
	return ans;
}
int main() {
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	if(W<w&&H<w||W<h&&H<h) {
		cout<<"-1";
		return 0;
	}
	cout<<min(an(W,w)+an(H,h),an(W,h)+an(H,w));
}
