#ifndef QUEUE_H
#define QUEUE_H
#include"AllTypeDefinition.h"

//队列的操作集 
Queue * CreateQueue();				//生成长度为MAXSIZE的新队列 
//int IsFullQ(Queue * Q);				//判断队列是否已满，已满则返回1，否则返回0 
void AddQ(Queue * Q,QueueElem item);	//队列已满则打印已满信息返回，否则将元素item插入 
int IsEmptyQ(Queue * Q);			//判断队列是否为空，空则返回1，否则返回0 
QueueElem DeleteQ(Queue * Q);		//若队列为空，打印空信息并返回，否则删除【队头】元素并返回 


#endif
