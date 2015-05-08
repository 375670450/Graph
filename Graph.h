#ifndef GRAPH_H
#define GRAPH_H

#include "AllTypeDefinition.h"

void CreateMGraph(MGraph * G);
void CreateALGraph(ALGraph * G);
void Destroy(Graph G);
int FindVertex(ALGraph *G,VertexType V);			//找到对应顶点的序号 
int FindVertexMG(MGraph * G,VertexType V); 

Graph InsertVertex(Graph G,Vertex V);
Graph InsertEdge(Graph G,Vertex V1,Vertex V2);
ALGraph *InsertEdgeAL(ALGraph *G,Vertex V1,Vertex V2,int Value);
Graph DeleteVertex(Graph G,Vertex V);				//删除G中顶点V及其相关边，并将结果图返回
Graph DeleteEdge(Graph G,Vertex V1,Vertex V2);

Boolean Empty(Graph G);
Vertex FirstAdjV(Graph G,Vertex V);					//返回V的第一个邻接点的位置，若V在G中没有邻接点则返回NULL 
Vertex NextAdjV(Graph G,Vertex V1,Vertex V2);		//返回V1的（对于V2的）下一个邻接点，若V2是V1的而最后一个邻接点则返回NULL 

void DFS(ALGraph *G,int i);
void DFS_ALG(ALGraph *G);
void BFS(ALGraph *G,int i);
void BFS_ALG(ALGraph * G);

int IsCircle(ALGraph * G);
void ToplogicalSort(ALGraph * G);		//拓扑排序 
void CriticalPath(ALGraph * G);

#endif 
