#ifndef MINSPANTREE_H
#define MINSPANTREE_H
#include "AllTypeDefinition.h"


int FindMGMin(MGraph * G,int LowCost[]);
int FindMin(ALGraph * G,int LowCost[]);
void PrimMG(MGraph * G);
void PrimALG(ALGraph * G);
void KruskalMG(MGraph * G);
void KruskalALG(ALGraph * G);
// Prim算法：从根节点长出一棵树
// Kruskal算法：把初始包含N个孤立顶点的森林逐步合成一棵生成树 

#endif


