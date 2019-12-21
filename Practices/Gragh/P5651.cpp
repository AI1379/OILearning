#include<bits/stdc++.h>
using namespace std;
struct node{
    int weight;
    int to;
}
vector<node>lst[100001];
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
void dfs(int vex){
    vis[vex]=true;
    int i,length;
    length=lst[i].size();
}
int main(){
    int i,j,x,y,v;
    node tmp;
    cin>>n>>m>>q;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            mp[i][j]=-1;
        }
    }
    for(i=0;i<m;i++){
        cin>>x>>y>>v;
        tmp.to=y;
        tmp.weight=v;
        lst[x].push_back(tmp);
        tmp.to=x;
        lst[y].push_back(tmp);
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