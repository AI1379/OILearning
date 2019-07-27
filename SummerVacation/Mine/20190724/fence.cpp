/*#include<bits/stdc++.h>
using namespace std;
bool arc[510][510],visited[510];
int f;
void DFS(int vex){
	int i;
	if(!visited[vex])
		cout<<vex<<endl;
	visited[vex]=true;
	for(i=1;i<=f;i++){
		if(arc[vex][i]){
			arc[vex][i]=false;
			DFS(i);
		}
	}
}
int main(){
	int x,y,i,j,num,start;
	memset(arc,false,sizeof(arc));
	memset(visited,false,sizeof(visited));
	cin>>f;
	for(i=1;i<=f;i++){
		cin>>x>>y;
		arc[x][y]=true;
		arc[y][x]=true;
	}
	start=1;
	for(i=1;i<f;i++){
		num=0;
		for(j=1;j<=f;j++){
			if(arc[i][j])
				num++;
		}
		if(num%2==0){
			start=i;
			break;
		}
	}
	cout<<start;
	DFS(start);
	return 0;
}*/
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 101
int g[maxn][maxn];               //此图用邻接矩阵存储
int du[maxn];                    //记录每个点的度，就是相连的边的数目
　　int circuit[maxn];               //用来记录找到的欧拉路的路径
　　int n,e,circuitpos,i,j,x,y,start;
　　void find_circuit(int i)         //这个点深度优先遍历过程寻找欧拉路
　　{
　　    int j;
　　    for (j = 1; j <= n; j++)
　　      if (g[i][j] == 1)          //从任意一个与它相连的点出发
　　       {
　　            g[j][i] = g[i][j] = 0; 
　　            find_circuit(j);
　　        } 
　　    circuit[++circuitpos] = i;   //记录下路径
　　}

　　int main()
　　{
　　    memset(g,0,sizeof(g));
　　    cin >> n >> e;
　　    for (i = 1; i <= e; i++)
　　    {
　　        cin >> x >> y;
　　        g[y][x] = g[x][y] = 1;
　　        du[x]++;                    //统计每个点的度
　　        du[y]++;
　　    }
　　    start = 1;                      //如果有奇点，就从奇点开始寻找，这样找到的就是
　　    for (i = 1; i <= n; i++)        //欧拉路。没有奇点就从任意点开始，
　　       if (du[i]%2 == 1)            //这样找到的就是欧拉回路。(因为每一个点都是偶点)
              start = i;
　　    circuitpos = 0;
　　    find_circuit(start);
　　    for (i = 1; i <= circuitpos; i++)
　　        cout << circuit[i] << ' ';
　　    cout << endl;
　　    return 0;
　　}


