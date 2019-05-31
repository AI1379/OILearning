#include<bits/stdc++.h>
using namespace std;
struct sp{
	int num;
	int step=50000;
}b[5001];
int n;
int main(){
	freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>b[i].num;
	}
	b[1].step=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[i].num&&(i+j)<=n;j++){
			if((b[i].step+1)<=b[i+j].step)b[i+j].step=b[i].step+1;
		}
	}
	cout<<b[n].step;
	return 0;
} 
