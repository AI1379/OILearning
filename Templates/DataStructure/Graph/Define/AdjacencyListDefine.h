typedef char VertexType;
typedef int EdgeType;
#define MaxVex 100
#define Infinity 65535
struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    EdgeNode *next;
};
struct VertexNode
{
    VertexType data;
    EdgeType *firstedge;
};
typedef VertexNode AdjList;
struct GraphAdjList
{
    AdjList adjList[MaxVex];
    int numVertexes,numEdges;
};
#ifndef _IOSTREAM_
#include <iostream>
using namespace std;
#endif
void CreateALGraph(GraphAdjList *G)
{
    int i,j,k;
    EdgeNode *e;
    //cout<<"Enter numVertexes and numEdges"<<endl;
    cin>>G->numVertexes>>G->numEdges;
    for(i=0;i<G->numVertexes;i++)
    {
        cin>>G->adjList[i].data;
        G->adjList[i].firstedge=NULL;
    }
    for(k=0;k<G->numEdges;k++)
    {
        //cout<<"Enter edge(vi,ji)'s vertex number"<<endl;
        cin>>i>>j;
        e=new EdgeNode;
        e->adjvex=j;
        e->next=G->adjList[i].firstedge;
        G->adjList[i].firstedge=e;
        e=new EdgeNode;
        e->adjvex=i;
        e->next=G->adjList[j].firstedge;
        G->adjList[j].firstedge=e;
    }
}
//无向图