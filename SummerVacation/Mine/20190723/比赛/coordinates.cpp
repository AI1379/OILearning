#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
bool cmpx(point A,point B){
	return A.x>B.x;
}
bool cmpy(point A,point B){
	return A.y>B.y;
}
int n,maxx,maxy,minx,miny;
bool coordinate[211][211];
point pointlist[251];
int main(){
	int i,j;
	memset(coordinate,false,sizeof(coordinate));
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>pointlist[i].x>>pointlist[i].y;
		coordinate[105+pointlist[i].x][105+pointlist[i].y]=true;
	}
	sort(pointlist,pointlist+n,cmpx);
	maxx=pointlist[0].x+105;
	minx=pointlist[n-1].x+105;
	sort(pointlist,pointlist+n,cmpy);
	maxy=pointlist[0].y+105;
	miny=pointlist[n-1].y+105;
	for(i=max(maxy,105);i>=min(miny,105);i--){
		for(j=min(minx,105);j<=max(maxx,105);j++){
			if(coordinate[j][i])
				cout<<'*';
			else if(j==105&&i==105)
				cout<<'+';
			else if(j==105&&i!=105)
				cout<<'|';
			else if(j!=105&&i==105)
				cout<<'-';
			else
				cout<<'.';
		}
		cout<<endl;
	}
	return 0;
}
