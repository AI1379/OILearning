#include<bits/stdc++.h>
using namespace std;
long double a[1001],Ayumi,Mitsuhiko,Genta;
int i,j,n,k;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin>>n>>k;
	a[0]=n;
	j=0;
	Ayumi=0;
	Mitsuhiko=0;
	Genta=0;
	for(i=1;i<k;i++){
		a[i]=sqrt((a[i-1]*a[i-1])/2);
	}
	int i=0;
	for(;i<k;){
		Ayumi=Ayumi+a[i];
		j++;
		if(j>=4){
			i++;
			j=0;
			if(i>=k){
				break;
			}
		}
		Mitsuhiko=Mitsuhiko+a[i];
		j++;
		if(j>=4){
			i++;
			j=0;
			if(i>=k){
				break;
			}
		}
		Genta=Genta+a[i];
		j++;
		if(j>=4){
			i++;
			j=0;
			if(i>=k){
				break;
			}
		}
	}
	cout<<Ayumi<<" "<<Mitsuhiko<<" "<<Genta;
	return 0;
}
