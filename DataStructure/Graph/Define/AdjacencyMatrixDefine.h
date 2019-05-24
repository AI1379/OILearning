typedef char VertexType;
typedef int EdgeType;
#define MaxVex 9
#define Infinity 65535
struct MGraph
{
    VertexType vexs[MaxVex];
    EdgeType arc[MaxVex][MaxVex];
    int numVertexes,numEdges;
};
#ifndef IOSTREAM
#include <iostream>
using namespace std;
#endif
void CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    //cout<<"Enter numVertexes and numEdges"<<endl;
    cin>>G->numVertexes>>G->numEdges;
    if(G->numVertexes>MaxVex||G->numEdges>(G->numVertexes-1)*G->numVertexes/2)
        return ;
    for(i=0;i<G->numVertexes;i++)
        cin>>G->vexs[i];
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
            G->arc[i][j]=Infinity;
    for(i=0;i<G->numVertexes;i++)
        G->arc[i][i]=0;
    for(k=0;k<G->numEdges;k++)
    {
        //cout<<"Enter edge(vi,vj)'s under number i,j and weight"<<endl;
        cin>>i>>j>>w;
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
    return ;
}
//无向网图