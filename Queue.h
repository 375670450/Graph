#ifndef QUEUE_H
#define QUEUE_H
#include"AllTypeDefinition.h"

//���еĲ����� 
Queue * CreateQueue();				//���ɳ���ΪMAXSIZE���¶��� 
//int IsFullQ(Queue * Q);				//�ж϶����Ƿ������������򷵻�1�����򷵻�0 
void AddQ(Queue * Q,QueueElem item);	//�����������ӡ������Ϣ���أ�����Ԫ��item���� 
int IsEmptyQ(Queue * Q);			//�ж϶����Ƿ�Ϊ�գ����򷵻�1�����򷵻�0 
QueueElem DeleteQ(Queue * Q);		//������Ϊ�գ���ӡ����Ϣ�����أ�����ɾ������ͷ��Ԫ�ز����� 


#endif
