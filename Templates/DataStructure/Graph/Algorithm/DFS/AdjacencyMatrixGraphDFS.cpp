#include <iostream>
#include "../Define/AdjacencyMatrixDefine.h"
using namespace std;
bool visited[MaxVex];
void DFS(MGraph G,int i)
{
    int j;
    visited[i]=true;
    cout<<G.vexs[i];
    for(j=0;j<G.numVertexes;j++)
        if(G.arc[i][j]==1&&!visited[j])
            DFS(G,j)
}
int main()
{
    int i;
    MGraph G;
    CreateMGraph(&G);
    for(i=0;i<G.numVertexes;i++)
        visited[i]=true;
    for(i=0;i<G.numVertexes;i++)
        if(!visited[i])
            DFS(G,i);
    return 0;
}