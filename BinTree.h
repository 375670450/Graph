#ifndef BINTREE_H
#define BINTREE_H
#include"AllTypeDefinition.h"
//���Ĳ�����

Boolean IsEmpty(BinTree BT);			//Boolean�͵ĺ���������ֵΪTRUE��FALSE 
BinTree CreateBinTree();				//�������Ĵ���
BinTree CreateTreeNode(ElementType Data);		//����һ����� 
void InOrderTraversal(BinTree BT);		//���������������
void PostOrderTraversal(BinTree BT);	//�������ĺ������ 
void LevelOrderTraversal(BinTree BT);	//�������Ĳ������ 
void PreOrderPrintLeaves(BinTree BT);	//�����������Ҷ�ڵ㣨�ݹ��㷨�� 
int  GetHeight(BinTree BT);				//���ظ߶� 
int  PostOrderGetHeight(BinTree BT);	//�ú����������������߶ȣ���ȣ� 

#endif 
