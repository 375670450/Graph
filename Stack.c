#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

Stack * CreateStack(){
	Stack * PtrS = (Stack*)malloc(sizeof(Stack));
	PtrS->next = NULL;
	return PtrS;
}

int IsEmptyS(Stack * S){
	int flag = 0;						//Ĭ�Ϸǿ� 
	if( S->next==NULL ){
		flag = 1;
	}
	return flag;
}

void Push(Stack * S,StackElem item){				//�����SҲ�ǿյ�ͷ��� 
	//���������ж� IsFull�ɱ�̫�ߣ����ﲻ���ж�ֱ��ѹջ 
	Stack *t = (Stack*)malloc(sizeof(Stack));
	t->Data = item;
	t->next = S->next;					//����S�ǿ�ͷ��㣬���ܶ�Sֱ�Ӳ�����ֻ����S->next!!!!! 
	S->next = t;
	return ;
}

StackElem Pop(Stack * S){
	StackElem TopElem;
	Stack * tmp;					//������ʱ��Ŷ�ջ������Ľ�㣨��ͷ����next�� 
	if( !IsEmptyS(S) ){
		TopElem = S->next->Data;
		tmp = S->next;
		S->next = tmp->next;
		free(tmp);
		return TopElem;
	}else{
		printf("Stack Empty \n");
		return 0;
	}
}	  								

