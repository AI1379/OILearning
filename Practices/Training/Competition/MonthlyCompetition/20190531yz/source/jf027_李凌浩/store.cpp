#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,h[31];
void m(int x){
	cout<<x<<endl;
}
void n(int x1,int x2){
	int j=x1;
	while(x2>=h[j]){
		j--;
	}
	m(j/3+1);
}
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	for(int i=1;i<=30;i++){
		if(i%3==0) h[i]=i;
		else if(i%3==1) h[i]=i+1;
		else if(i%3==2) h[i]=i-1;
	} 
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		if(c==0) n(a,b);
		else if(a==1||b==1) m(1);
		else if(a==0||b==0) m(0);
		else if(a<=2&&b<=2) m(1);
		else if(a==2&&b>=3) m(2);
		else if(a==3&&b>=2&&b<=4) m(2);
		else if(a==3&&b>=5) m(3);
		else if(a==4&&b>=2&&b<=3) m(2);
		else if(a==4&&b>=4&&b<=5) m(3);
		else if(a==4&&b>=6&&c<2) m(3);
		else if(a==4&&b>=6&&c>=2) m(4);
		else if(a>=5&&b==2) m(2);
		else if(a==5&&b>=3&&b<=5) m(3);
		else if(a==5&&b>=6&&b<=7) m(4);
		else if(a==5&&b>=8&&c<2) m(4);
		else if(a==5&&b>=8&&c>=2) m(5);
		else if(a==6&&b>=3&&b<=4) m(3);
		else if(a==6&&b>=5&&b<=7) m(4);
		else if(a==6&&b>=8&&b<=9) m(5);
		else if(a==6&&b>=10&&c<2) m(5);
		else if(a==6&&b>=10&&c>=2) m(6);
	}
	return 0;
}
