#ifndef SHORTPATH_H
#define SHORTPATH_H
#include "AllTypeDefinition.h"

void DijkstraMG(MGraph * G,int v0);
int FindMGShort(MGraph * G,int D[],int Arrived[]);

void Dijkstra(ALGraph * G,int v0);
int FindShort(ALGraph * G,int D[],int Arrived[]);

void PrintSP(int P[],int n);		//�õݹ�������·�� 

void FloydMG(MGraph * G);
#endif


