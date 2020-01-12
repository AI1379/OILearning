#include<bits/stdc++.h>
using namespace std;
int x1[100001],x2[100001],y2[100001],y3[100001];
int main(){
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	double n,ans,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x1[i]>>y2[i]>>x2[i]>>y3[i];
		k=x1[i]*y2[i];
		if(fabs(ans)<fabs(k)) ans=k;
		else{
			if(fabs(ans)==fabs(k)&&k<ans) ans=k;
		}
	}
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
