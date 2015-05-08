#ifndef MINSPANTREE_H
#define MINSPANTREE_H
#include "AllTypeDefinition.h"


int FindMGMin(MGraph * G,int LowCost[]);
int FindMin(ALGraph * G,int LowCost[]);
void PrimMG(MGraph * G);
void PrimALG(ALGraph * G);
void KruskalMG(MGraph * G);
void KruskalALG(ALGraph * G);
// Prim�㷨���Ӹ��ڵ㳤��һ����
// Kruskal�㷨���ѳ�ʼ����N�����������ɭ���𲽺ϳ�һ�������� 

#endif


