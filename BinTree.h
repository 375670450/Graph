#ifndef BINTREE_H
#define BINTREE_H
#include"AllTypeDefinition.h"
//树的操作集

Boolean IsEmpty(BinTree BT);			//Boolean型的函数，返回值为TRUE或FALSE 
BinTree CreateBinTree();				//二叉树的创建
BinTree CreateTreeNode(ElementType Data);		//生成一个结点 
void InOrderTraversal(BinTree BT);		//二叉树的中序遍历
void PostOrderTraversal(BinTree BT);	//二叉树的后序遍历 
void LevelOrderTraversal(BinTree BT);	//二叉树的层序遍历 
void PreOrderPrintLeaves(BinTree BT);	//输出二叉树的叶节点（递归算法） 
int  GetHeight(BinTree BT);				//返回高度 
int  PostOrderGetHeight(BinTree BT);	//用后序遍历法求二叉树高度（深度） 

#endif 
