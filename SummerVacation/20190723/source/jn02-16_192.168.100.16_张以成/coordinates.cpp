#include<bits/stdc++.h>
using namespace std;
struct lt {
	int x,y;
}mlt[250];
int n,minx,miny,maxx,maxy;
bool tf[200][200];
bool cmp(lt a,lt b){
	if(a.x<b.x){
		return true;
	}
	if(a.x==b.x&&a.y>b.y){
		return true;
	}
	return false;
}
int main(){
	freopen("coordinates.in","r"stdin);
	freopen("coordinates.out","w"stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>mlt[i].x>>mlt[i].y;
		if(mlt[i].x>maxx){
			maxx=mlt[i].x;
		}
		if(mlt[i].x<minx){
			minx=mlt[i].x;
		}
		if(mlt[i].y>maxy){
			maxy=mlt[i].y;
		}
		if(mlt[i].y<miny){
			miny=mlt[i].y;
		}
		tf[mlt[i].x+100][mlt[i].y+100]=true;
	}
	sort(mlt,mlt+n,cmp);
	/*
	for(int i=0;i<n;i++){
		cout<<mlt[i].x<<" "<<mlt[i].y<<endl;
	}
	*/
	for(int i=maxx;i>=minx;i--){
		for(int j=miny;j<=maxy;j++){
			if(i==0&&j==0&&tf[i+100][j+100]==false){
				cout<<"+";
			}
			if(i==0&&j!=0&&tf[i+100][j+100]==false){
				cout<<"-";
			}
			if(i!=0&&j==0&&tf[i+100][j+100]==false){
				cout<<"|";
			}
			if(i!=0&&j!=0&&tf[i+100][j+100]==false){
				cout<<".";
			}
			if(tf[i+100][j+100]==true){
				cout<<"*";
			}
		}
		cout<<endl;
	}
}
