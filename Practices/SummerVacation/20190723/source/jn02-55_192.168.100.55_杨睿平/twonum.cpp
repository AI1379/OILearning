#include <bits/stdc++.h>
using namespace std;
const int MOD=100000007;
int h1,a2,x1,yy1,h2,a1,x2,y2,m,t;
int xun[3][3];
long long w1,w2,z1,z2,ans;
bool p[1000420],f,f2;
int gcd(int a,int b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	scanf("%d",&t);
	int i,j,k,l;
	while(t>0){
		t--;
	  scanf("%d",&m);
	  scanf("%d%d",&h1,&a1);
	  scanf("%d%d",&x1,&yy1);
	  scanf("%d%d",&h2,&a2);
	  scanf("%d%d",&x2,&y2);
      memset(p,0,sizeof(p));
      memset(xun,0,sizeof(xun));
      w1=h1;
      l=1;
      f=f2=0;
      p[w1]=1;
      while(l<=2){
          w1=(w1*x1+yy1)%m;
          xun[1][l]++;
          if(w1==a1){
          	l++;
          	f=1;
		  }
          else{
          	if(p[w1]==1&&w1!=a1&&f==0){
          		cout<<"-1"<<endl;
          		f2=1;
          		break;
			}
		  }  
		  p[w1]=1;
	  }
		if(f2)continue;
		l=1;
		f2=f=0;
       memset(p,0,sizeof(bool)*m);
       w2=h2;
       p[w2]=1;
	    while(l<=2){
          w2=(w2*x2+y2)%m;
          xun[2][l]++;
          if(w2==a2){
          	l++;
          	f=1;
		  }
          else{
          	if(p[w2]==1&&w2!=a2&&f==0){
          		cout<<"-1"<<endl;
          		f2=1;
          		break;
			}
		  }  
		  p[w1]=1;
	  }
	  if(f2)continue;
	  z1=z2=ans=0;
	  cout<<xun[1][1]<<" "<<xun[1][2]<<" "<<xun[2][1]<<" "<<xun[2][2]<<endl;
	  while(1){
	  	if(xun[1][1]+xun[1][2]*ans==xun[2][1]+xun[2][2]*ans){
	  		cout<<xun[1][1]+xun[1][2]*ans<<endl;
	  		break;
		  }else{
		  	ans++;
		  }
	  }
	}
	return 0;
}
