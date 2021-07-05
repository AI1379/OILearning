#include<bits/stdc++.h>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
struct position{
  int x,y;
};
int n,m;
bool arc[1000][1000],visited[1000][1000];
queue <position> q;
int main(){
  int i,j,k,a,b,ans;
  char c;
  position tmp;
  cin>>n>>m;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      c=getchar();
      if(c=='0')
        arc[i][j]=false;
      else if(c=='1')
        arc[i][j]=true;
    }
  }
  for(k=0;k<m;k++){
    ans=0;
    memset(visited,false,sizeof(visited));
    while(!q.empty())
      q.pop();
    cin>>a>>b;
    tmp.x=a-1;tmp.y=b-1;
    q.push(tmp);
    while(!q.empty()){
      for(i=0;i<4;i++){
        for(j=0;j<4;j++){
          tmp.x=q.front().x+dx[i];
          tmp.y=q.front().y+dy[j];
          if((0<=tmp.x&&tmp.x<n)&&(0<=tmp.y&&tmp.y<n)){
            if(!visited[tmp.x][tmp.y]&&(arc[tmp.x][tmp.y]^arc[q.front().x][q.front().y])){
              q.push(tmp);
              visited[tmp.x][tmp.y]=true;
              ans++;
            }
          }
        }
      }
      q.pop();
    }
    cout<<ans<<endl;
  }
  return 0;
}
