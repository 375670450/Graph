#ifndef GRAPH_H
#define GRAPH_H

#include "AllTypeDefinition.h"

void CreateMGraph(MGraph * G);
void CreateALGraph(ALGraph * G);
void Destroy(Graph G);
int FindVertex(ALGraph *G,VertexType V);			//�ҵ���Ӧ�������� 
int FindVertexMG(MGraph * G,VertexType V); 

Graph InsertVertex(Graph G,Vertex V);
Graph InsertEdge(Graph G,Vertex V1,Vertex V2);
ALGraph *InsertEdgeAL(ALGraph *G,Vertex V1,Vertex V2,int Value);
Graph DeleteVertex(Graph G,Vertex V);				//ɾ��G�ж���V������رߣ��������ͼ����
Graph DeleteEdge(Graph G,Vertex V1,Vertex V2);

Boolean Empty(Graph G);
Vertex FirstAdjV(Graph G,Vertex V);					//����V�ĵ�һ���ڽӵ��λ�ã���V��G��û���ڽӵ��򷵻�NULL 
Vertex NextAdjV(Graph G,Vertex V1,Vertex V2);		//����V1�ģ�����V2�ģ���һ���ڽӵ㣬��V2��V1�Ķ����һ���ڽӵ��򷵻�NULL 

void DFS(ALGraph *G,int i);
void DFS_ALG(ALGraph *G);
void BFS(ALGraph *G,int i);
void BFS_ALG(ALGraph * G);

int IsCircle(ALGraph * G);
void ToplogicalSort(ALGraph * G);		//�������� 
void CriticalPath(ALGraph * G);

#endif 
