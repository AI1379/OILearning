#include<bits/stdc++.h>
using namespace std;
struct zb{
	int x;
	int y;
};
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	
	bool dmap[301][301];
	int n;cin >> n;
	zb s[n + 1];
	for(int i = 1;i <= n;i++) cin >> s[i].x >> s[i].y;
	
	int x_max = -1000,x_min = 1000;
	int y_max = -1000,y_min = 1000;
	for(int i = 1;i <= n;i++){
		x_max = max(x_max,s[i].x);
		x_min = min(x_min,s[i].x);
		y_max = max(y_max,s[i].y);
		y_min = min(y_min,s[i].y);
		dmap[s[i].y + 100][s[i].x + 100] = 1;
	}
	
	
	if(x_min >= 0 && y_min >= 0){
		for(int i = y_max;i >= 0;i--){
		for(int j = 0;j <= x_max;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
		}
	}
	else if(x_max <= 0 && y_max <= 0){
		for(int i = 0;i >= y_min;i--){
		for(int j = x_min;j <= 0;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
		}
	}
	else if(x_max <= 0 && y_min >= 0){
		for(int i = y_max;i >= 0;i--){
		for(int j = x_min;j <= 0;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
		}
	}
	else if(x_min >= 0 && y_max <= 0){
		for(int i = 0;i >= y_min;i--){
		for(int j = 0;j <= x_max;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
		}
	}
	else if(y_min >= 0){
		for(int i = y_max;i >= 0;i--){
		for(int j = x_min;j <= x_max;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
	}
	}
	else if(y_max <= 0){
		for(int i = 0;i >= y_min;i--){
		for(int j = x_min;j <= x_max;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
	}
	}
	else if(x_max <= 0){
		for(int i = y_max;i >= y_min;i--){
		for(int j = x_min;j <= 0;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
	}
	}
	else if(x_min >= 0){
		for(int i = y_max;i >= y_min;i--){
		for(int j = 0;j <= x_max;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
	}
	}
	else{
		for(int i = y_max;i >= y_min;i--){
		for(int j = x_min;j <= x_max;j++){
			if(dmap[i+100][j+100]) cout << "*";
			else if(i == 0 && j == 0) cout << "+";
			else if(j == 0) cout << "|";
			else if(i == 0) cout << "-";
			else cout << ".";
		}
		cout << endl;
	}
	}
}
