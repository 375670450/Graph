#ifndef MAXHEAP_H
#define MAXHEAP_H
#include"AllTypeDefinition.h"
//堆的最常用结构是用二叉树表是，若不特指，它是一棵完全二叉树
//最大堆：每个结点的元素都要大于其子结点元素 
//有关公式：下标为i的结点，其父节点下表为i/2,左右子结点下标分别为2i,2i+1
//因此相比于二叉树，更方便操作其父节点 
//(下标从1开始，指针坐标为0处不存放数据)



//最大堆的操作集 
MaxHeap CreateMaxHeap();
Boolean IsFullMax(MaxHeap H);
MaxHeap MaxHeapInsert(MaxHeap H,MaxHeapElem item);		//返回的仍然是原来的H 
Boolean IsEmptyMax(MaxHeap H);
MaxHeapElem DeleteMax(MaxHeap H); 		//删除并返回最大的元素 
MaxHeap BuildMaxHeap(MaxHeap H);	//将一个无序堆调整为最大堆 
void MaxHeapPrint(MaxHeap H);

#endif
