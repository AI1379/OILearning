#include<bits/stdc++.h>
using namespace std;
int main(){
	int W,H,w,h,ans1,ans2;
	double tmp1,tmp2;
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	if((W<w&&H<w)||(W<h&&H<h)){
		cout<<"-1";
	}
	else{
		ans1=0;
		tmp1=(double)(W);
		tmp2=(double)(H);
		while(fabs(tmp1-w)>0.00001){
			tmp1/=2.00;
			ans1++;
		}
		while(fabs(tmp2-h)>0.00001){
			tmp2/=2;
			ans1++;
		}
		ans2=0;
		tmp1=W;
		tmp2=H;
		while(fabs(tmp1-h)>0.00001){
			tmp1/=2;
			ans2++;
		}
		while(fabs(tmp2-w)>0.00001){
			tmp2/=2;
			ans2++;
		}
		cout<<min(ans1,ans2);
	}
	return 0;
}
