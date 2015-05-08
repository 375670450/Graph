#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"


Queue * CreateQueue(){
	Queue * PtrQ ;
	PtrQ = (Queue*)malloc(sizeof(Queue));
	PtrQ->front = PtrQ->rear = NULL;
	return PtrQ;
}


int IsEmptyQ(Queue * PtrQ){
	int flag = 0;				//Ĭ�Ϸǿ� 
	if( PtrQ->front==PtrQ->rear && PtrQ->front==NULL ){	
		flag = 1;
	}
	return flag;
} 


void AddQ(Queue * PtrQ,QueueElem item){
//	if( !IsFullQ(PtrQ) ){					//�޷����ж��Ƿ�������ʡȥ�ò��� 
		QNode * t = (QNode*)malloc(sizeof(QNode));
		t->Data = item;
		t->Next = NULL;
		if( IsEmptyQ(PtrQ) ){
			PtrQ->front = PtrQ->rear = t;
			PtrQ->front->Next = PtrQ->rear->Next = t;
		}else{
			PtrQ->rear->Next = t;
			PtrQ->rear = t;
		}
//	}else{
//		printf("Queue Full \n");
//	}
	return ;
}

QueueElem DeleteQ(Queue * PtrQ){
	if( !IsEmptyQ(PtrQ) ){
		QNode * FrontCell;
		QueueElem FrontElem;
		FrontCell = PtrQ->front;
		FrontElem = FrontCell->Data;
		if( PtrQ->front == PtrQ->rear ){			//ֻ��һ��Ԫ�� 
			PtrQ->front = PtrQ->rear = NULL;		//������Ϊ�� 
		}else{
			PtrQ->front = PtrQ->front->Next; 
		}
		free(FrontCell);
		return FrontElem;
	}else{
		printf("Queue Empty \n");
		return NULL;
//		system("Pause");
	}
}



