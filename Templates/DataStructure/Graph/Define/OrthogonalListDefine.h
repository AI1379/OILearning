typedef char VertexType;
typedef int EdgeType;
#define MaxVex 100
#define Infinity 65535
struct EdgeNode
{
    int tailVex,headVex;
    EdgeType weight;
    EdgeNode *headlink,*taillink;
};
struct VertexNode
{
    VertexType data;
    EdgeType *firstin,*firstout;
};
typedef VertexNode AdjList;
struct GraphOrthList
{
    AdjList adjList[MaxVex];
    int numVertexes,numEdges;
};