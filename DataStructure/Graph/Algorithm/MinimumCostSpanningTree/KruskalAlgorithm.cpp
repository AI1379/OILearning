#include <iostream>
//#include <windows.h>
#include "..\..\Define\EdgeSetArray.h"
int Find(int *parent,int f)
{
    while(parent[f]>0)
        f=parent[f];
    return f;
}
int main()
{
    //cout<<"(begin,end) weight"<<endl;
    int i,n,m;
    ESAGraph G;
    int parent[MaxVex];
    CreateESAGraph(&G);
    for(i=0;i<G.numVertexes;i++)
        parent[i]=0;
    for(i=0;i<G.numEdges;i++)
    {
        n=Find(parent,G.edges[i].begin);
        m=Find(parent,G.edges[i].end);
        if(n!=m)
        {
            parent[n]=m;
            cout<<'('<<G.edges[i].begin<<','<<G.edges[i].end<<") "<<G.edges[i].weight<<endl;
        }
    }
    //system("pause");
    return 0;
}