#include<bits/stdc++.h>
using namespace std;
const int dx[6]={1,-1,0,0,0,0};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};
struct point{
    int x,y,z;
};
bool vis[101][101][101];
queue<point>q;
int l,m,n;
bool side(point p){
    bool flag1,flag2,flag3;
    flag1=(p.x==1||p.x==l);
    flag2=(p.y==1||p.y==m);
    flag3=(p.z==1||p.z==n);
    return flag1||flag2||flag3;
}
int main(){
    int i,j,k,tmp,ans=0,x,y,z;
    bool flag;
    point start;
    cin>>l>>m>>n;
    for(i=1;i<=l;i++){
        for(j=1;j<=m;j++){
            for(k=1;k<=n;k++){
                cin>>tmp;
                vis[i][j][k]=(tmp==1);
            }
        }
    }
    for(i=2;i<l;i++){
        for(j=2;j<m;j++){
            for(k=2;k<n;k++){
                if(vis[i][j][k])continue;
                while(!q.empty())q.pop();
                start.x=i;start.y=j;start.z=k;
                q.push(start);
                flag=true;
                while(!q.empty()){
                    if(side(q.front())){
                        flag=false;
                    }
                    for(tmp=0;tmp<6;tmp++){
                        x=q.front().x+dx[tmp];
                        y=q.front().y+dy[tmp];
                        z=q.front().z+dz[tmp];
                        if(1<=x&&x<=l&&1<=y&&y<=m&&1<=z&&z<=n&&!vis[x][y][z]){
                            vis[x][y][z]=true;
                            start.x=x;start.y=y;start.z=z;
                            q.push(start);
                        }
                    }
                    q.pop();
                }
                if(flag)ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
in:
3 4 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

1 1 1 1 1
1 0 0 1 1
1 0 1 0 0
1 1 1 1 1

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
out:
1
*/