#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
bool visited[510][510];
int mp[510][510];
int h,w,m,ans=0;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	queue<pair<int,int> >q;
	memset(visited,0,sizeof(visited));
	int i,j,k,x,y;
	bool flag,flag2;
	cin>>h>>w>>m;
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			cin>>mp[i][j];
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cout<<mp[i][j]<<' ';
		}
		cout<<endl;
	}
	for(k=0;k<h;k++){
		for(j=0;j<w;j++){
			if(!visited[i][j]){	
				q.push(make_pair(i,j));
				while(!q.empty()){
					flag=false;
					for(i=0;i<4;i++){
						x=q.front().first+dx[i];
						y=q.front().second+dy[i];
						if(0<=x&&x<h&&0<=y&&y<w){
							if(abs(mp[x][y]-mp[q.front().first][q.front().second])<=m&&!visited[x][y]){
								q.push(make_pair(x,y));
								visited[x][y]=true;
								flag=true;
							}
						}
					}
					q.pop();
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3 4 1
2 0 0 0
0 0 2 2
0 0 2 2
*/
