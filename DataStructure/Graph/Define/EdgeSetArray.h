typedef char VertexType;
typedef int EdgeType;
#define MaxVex 9
#define MaxEdge (MaxVex*(MaxVex-1)/2)
#define Infinity 65535
struct Edge{
    int begin;
    int end;
    int weight;
};
struct ESAGraph{
    VertexType vexs[MaxVex];
    Edge edges[MaxEdge];
    int numVertexes,numEdges;
};
#ifndef IOSTREAM
#include <iostream>
using namespace std;
#endif
void CreateESAGraph(ESAGraph *G)
{
    int i;
    cin>>G->numVertexes>>G->numEdges;
    if(G->numVertexes>MaxVex||G->numEdges>(G->numVertexes-1)*G->numVertexes/2)
        return ;
    for(i=0;i<G->numVertexes;i++)
        cin>>G->vexs[i];
    for(i=0;i<G->numEdges;i++)
        cin>>G->edges[i].begin>>G->edges[i].end>>G->edges[i].weight;
    return ;
}
//无向网图