#include<bits/stdc++.h>
using namespace std;
bool ans[1024][1024];
int power[11]={1,2,4,8,16,32,64,128,256,512,1024};
void build(int n,int x,int y){
    int i,j;
    if(n==1){
        ans[x][y]=false;
        ans[x+1][y]=true;
        ans[x][y+1]=true;
        ans[x+1][y+1]=true;
        return ;
    }
    for(i=0;i<power[n-1];i++)
        for(j=0;j<power[n-1];j++)
            ans[i][j]=false;
    build(n-1,x,y+power[n-1]);
    build(n-1,x+power[n-1],y);
    build(n-1,x+power[n-1],y+power[n-1]);
    return ;
}
int main(){
    int n,i,j;
    cin>>n;
    memset(ans,false,sizeof(ans));
    build(n,0,0);
    for(i=0;i<power[n];i++){
        for(j=0;j<power[n];j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}