#include<bits/stdc++.h>
using namespace std;
int mp[10000][10000],dis[100000];
bool vis[100000];
int m,n,q;
void DFS(int vex){
    vis[vex]=true;
    int i;
    for(i=0;i<n;i++){
        if(mp[vex][i]!=-1&&!vis[i]){
            dis[i]=dis[vex]^mp[vex][i];
            DFS(i);
        }
    }
    return ;
}
int main(){
    int i,j,x,y,v;
    cin>>n>>m>>q;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            mp[i][j]=-1;
        }
    }
    for(i=0;i<m;i++){
        cin>>x>>y>>v;
        mp[x-1][y-1]=v;
        mp[y-1][x-1]=v;
    }
    memset(dis,0,sizeof(dis));
    DFS(0);
    for(i=0;i<q;i++){
        cin>>x>>y;
        cout<<(dis[x-1]^dis[y-1])<<endl;
    }
    system("pause");
    return 0;
}