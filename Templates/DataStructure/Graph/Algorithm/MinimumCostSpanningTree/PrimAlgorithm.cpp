#include <iostream>
//#include <windows.h>
#include "..\..\Define\AdjacencyMatrixDefine.h"
int main()
{ 
    //cout<<"(begin,end) weight"<<endl;  
    MGraph G;
    CreateMGraph(&G);
    int min,i,j,k;
    int adjvex[MaxVex];
    int lowcost[MaxVex];
    lowcost[0]=0;
    adjvex[0]=0;
    for(i=0;i<G.numVertexes;i++)
    {
        lowcost[i]=G.arc[0][i];
        adjvex[i]=0;
    }
    for(i=1;i<G.numVertexes;i++)
    {
        min=Infinity;
        k=0;
        for(j=1;j<G.numVertexes;j++)
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
        cout<<'('<<adjvex[k]<<','<<k<<')'<<G.arc[adjvex[k]][k]<<endl;
        lowcost[k]=0;
        for(j=1;j<G.numVertexes;j++)
        {
            if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
            {
                lowcost[j]=G.arc[k][j];
                adjvex[j]=k;
            }
        }
    }
    //system("pause");
    return 0;
}