#ifndef MAXHEAP_H
#define MAXHEAP_H 
#include"AllTypeDefinition.h"

//��С�ѵĲ����� 
MinHeap CreateMinHeap();
Boolean IsFullM(MinHeap H);
MinHeap MinHeapInsert(MinHeap H,MinHeapElem item);		//���ص���Ȼ��ԭ����H 
Boolean IsEmptyM(MinHeap H);
MinHeapElem DeleteMin(MinHeap H); 		//ɾ����������С��Ԫ�� 
MinHeap BuildMinHeap(MinHeap H);	//��һ������ѵ���Ϊ��С�� 
void MinHeapPrint(MinHeap H);

#endif

