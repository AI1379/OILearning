#include<bits/stdc++.h>
using namespace std;
const int dx[8]={1,2,-1,-2,1,2,-1,-2};
const int dy[8]={2,1,-2,-1,-2,-1,2,1};
struct positive{
  int x,y;
};
int m,n;
int ans[400][400];
bool visited[400][400];
queue <positive> q;
int main(){
  positive tmp;
  int i,j,k=0;
  cin>>n>>m>>tmp.x>>tmp.y;
  memset(visited,false,sizeof(visited));
  memset(ans,-1,sizeof(ans));
  visited[tmp.x][tmp.y]=true;
  ans[tmp.x][tmp.y]=0;
  q.push(tmp);
  while(!q.empty()){
    k++;
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
        tmp.x=q.front().x+dx[i];tmp.y=q.front().y+dy[j];
        if(!visited[tmp.x][tmp.y]&&((0<=tmp.x&&tmp.x<n)&&(0<=tmp.y&&tmp.y<m))){
          visited[tmp.x][tmp.y]=true;
          ans[tmp.x][tmp.y]=ans[q.front().x][q.front().y]+1;
          q.push(tmp);
        }
      }
    }
    q.pop();
  }
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cout<<left<<setw(5)<<ans[i][j];
    }
    cout<<endl;
  }
  return 0;
}
