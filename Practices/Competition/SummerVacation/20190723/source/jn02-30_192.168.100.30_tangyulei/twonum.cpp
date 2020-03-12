#include<bits/stdc++.h>
using namespace std;
int h1,h2,a1,a2,x1,x2,y1,y2,m;
int fa = -1;
int gcd(int x,int y){
	if(y == 0) return x;
	gcd(y,x % y);
}
int gs(int x,int y,int w){
	return (x * w + y) % m;
}
int zq(int x,int y,int w,int a){
	fa = -1;
	int begin1 = w,t = 0;
	bool flag = 1,flag2 = 1;
	while(begin1 != w || flag){
		flag = 0;
		begin1 = gs(x,y,begin1);

		if(flag2) fa++;
		if(begin1 == a && flag2){
			flag2 = 0;
		}
		t++;
	}
	if (flag2){
		cout << -1 << endl;
		exit;
	}
	
	fa++;
	cout << endl;
	return t;
}
void dw(){
	int T1 = zq(x1,y1,h1,a1);
	int fa1 = fa;
	int T2 = zq(x2,y2,h2,a2);
	int fa2 = fa;

	if (fa2 == fa1){
		cout << fa2 << endl;
		exit;
	}
	
	if (T1 == T2 && fa2 != fa1){
		cout << -1 << endl;
		exit;
	}
	
	int d,n1 = 0;
	if(T1 > T2){
		d = T1 - T2;
		if(fa1 > fa2){
			while(fa2 != fa1){
				n1++;
				fa2 += d;
				if(fa2 == fa1){
					break;
				}
				if(fa2 >= T2) fa2 -= T2;
			}
			cout << fa2 + n1 * T2 << endl;
		}else{
			while(fa2 != fa1){
				n1++;
				fa1 += d;
				if(fa2 == fa1){
					break;
				}
				if(fa1 >= T1) fa1 -=T1;
			}
			cout << fa2 + n1 * T2 << endl;
		}
	}else{
		d = -T1 + T2;
		if(fa1 > fa2){
			while(fa2 != fa1){
				n1++;
				fa2 += d;
				if(fa2 == fa1){
					break;
				}
				if(fa2 >= T2) fa2 -= T2;
			}
			cout << fa2 + n1 * T2 << endl;
		}else{
			while(fa2 != fa1){
				n1++;
				fa1 += d;
				if(fa2 == fa1){
					break;
				}
				if(fa1 >= T1) fa1 -=T1;
			}
			cout << fa1 + n1 * T1 << endl;
		}
	}

	
	
}
int main(){
	int n;cin >> n;
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	for(int i = 1;i <= n;i++){
		cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
		dw();
	}
}
