#include <iostream>
#include "../Define/AdjacencyListDefine.h"
using namespace std;
bool visited[MaxVex];
void DFS(GraphAdjList GL,int i)
{
    EdgeNode *p;
    visited[i]=true;
    cout<<GL.adjList[i].data;
    p=GL.adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL,p->adjvex);
        p=p->next;
    }
}
int main()
{
    int i;
    GraphAdjList GL;
    CreateALGraph(&GL);
    for(i=0;i<GL.numVertexes;i++)
        visited[i]=false;
    for(i=0;i<GL.numVertexes;i++)
        if(!visited[i])
            DFS(GL,i);
    return 0;
}