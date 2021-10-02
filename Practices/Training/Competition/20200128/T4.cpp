#include<bits/stdc++.h>
using namespace std;
int m,n,qes;
int w[5000];
bool arc[5000][5000];
bool vis[5000];
int ans[5000];
queue<int>q;
void bfs(int s){
    int u,i;
    while(!q.empty()){
        q.pop();
    }
    memset(vis,0,sizeof(vis));
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        u=q.front();
        for(i=0;i<n;i++){
            if(i!=u&&arc[u][i]&&!vis[i]){
                q.push(i);
                vis[i]=true;
                ans[s]=max(ans[s],w[i]);
                cout<<'-';
            }
        }
    }
}
int main(){
    int i,x,y;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>w[i];
        ans[i]=w[i];
    }
    for(i=0;i<m;i++){
        cin>>x>>y;
        arc[x-1][y-1]=true;
    }
    for(i=0;i<n;i++){
        bfs(i);
    }
    cin>>qes;
    for(i=0;i<qes;i++){
        cin>>x;
        cout<<ans[x-1]<<endl;
    }
    return 0;
}