#include<bits/stdc++.h>
using namespace std;
int T,m,h1,a1,x_1,y_1,h2,a2,x_2,y_2,w1,w2;
int p1,p2,t1,t2;
bool flg1,flg2;
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d%d%d%d%d%d",&m,&h1,&a1,&x_1,&y_1,&h2,&a2,&x_2,&y_2);
		w1=h1,w2=h2,t1=t2=0,flg1=flg2=false;
		w1=(w1*x_1+y_1)%m,t1++;
		while (w1!=h1){
			w1=(w1*x_1+y_1)%m,t1++;
			if (w1==a1) flg1=true,p1=t1;
		}
		w2=(w2*x_2+y_2)%m,t2++;
		while (w2!=h2){
			w2=(w2*x_2+y_2)%m,t2++;
			if (w2==a2) flg2=true,p2=t2;
		}
		if (!flg1||!flg2) printf("-1\n");
		else if (t1==t2&&p1!=p2) printf("-1\n");
		else{
			w1=h1,w2=h2;
			for (int i=1;i<=10000000;i++){
				w1=(w1*x_1+y_1)%m,w2=(w2*x_2+y_2)%m;
				if (w1==a1&&w2==a2){
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
