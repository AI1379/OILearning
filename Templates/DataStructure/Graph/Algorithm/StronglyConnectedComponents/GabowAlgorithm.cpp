#include<iostream>
#include"../../Define/AdjacencyListDefine.h"
map<VertexNode,bool>visited;
int main(){
    GraphAdjList G;
    stack<VertexNode>stk1,stk2;
    int Order[MaxVex];
    CreateALGraph(&G);
    memset(Order,-1,sizeof(Order));
    
}