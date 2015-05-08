#ifndef MAXHEAP_H
#define MAXHEAP_H
#include"AllTypeDefinition.h"
//�ѵ���ýṹ���ö��������ǣ�������ָ������һ����ȫ������
//���ѣ�ÿ������Ԫ�ض�Ҫ�������ӽ��Ԫ�� 
//�йع�ʽ���±�Ϊi�Ľ�㣬�丸�ڵ��±�Ϊi/2,�����ӽ���±�ֱ�Ϊ2i,2i+1
//�������ڶ�����������������丸�ڵ� 
//(�±��1��ʼ��ָ������Ϊ0�����������)



//���ѵĲ����� 
MaxHeap CreateMaxHeap();
Boolean IsFullMax(MaxHeap H);
MaxHeap MaxHeapInsert(MaxHeap H,MaxHeapElem item);		//���ص���Ȼ��ԭ����H 
Boolean IsEmptyMax(MaxHeap H);
MaxHeapElem DeleteMax(MaxHeap H); 		//ɾ������������Ԫ�� 
MaxHeap BuildMaxHeap(MaxHeap H);	//��һ������ѵ���Ϊ���� 
void MaxHeapPrint(MaxHeap H);

#endif
