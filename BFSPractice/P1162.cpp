#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
struct postion{
  int x,y;
};
int mat[30][30],ans[30][30],n;
bool visited[30][30],flag;
queue <postion> q;
int main(){
  postion tmp;
  int i,j,k;
  cin>>n;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      cin>>mat[i][j];
  memset(visited,false,sizeof(visited));
  flag=false;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(mat[i][j]!=1){
        tmp.x=i;tmp.y=j;
        flag=true;
        break;
      }
    }
    if(flag)break;
  }
  q.push(tmp);
  while(!q.empty()){
    for(k=0;k<4;k++){
      tmp.x=q.front().x+dx[k];tmp.y=q.front().y+dy[k];
      if(mat[tmp.x][tmp.y]==0&&!visited[tmp.x][tmp.y]){
        visited[tmp.x][tmp.y]=true;
        q.push(tmp);
      }
    }
    q.pop();
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(mat[i][j]==0&&!visited[i][j])
        cout<<"2 ";
      else if(visited[i][j])
        cout<<"0 ";
      else cout<<"1 ";
    }
    cout<<endl;
  }
  return 0;
}
