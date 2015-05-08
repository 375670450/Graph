#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

Stack * CreateStack(){
	Stack * PtrS = (Stack*)malloc(sizeof(Stack));
	PtrS->next = NULL;
	return PtrS;
}

int IsEmptyS(Stack * S){
	int flag = 0;						//默认非空 
	if( S->next==NULL ){
		flag = 1;
	}
	return flag;
}

void Push(Stack * S,StackElem item){				//这里的S也是空的头结点 
	//由于链表判断 IsFull成本太高，这里不用判断直接压栈 
	Stack *t = (Stack*)malloc(sizeof(Stack));
	t->Data = item;
	t->next = S->next;					//由于S是空头结点，不能对S直接操作，只操作S->next!!!!! 
	S->next = t;
	return ;
}

StackElem Pop(Stack * S){
	StackElem TopElem;
	Stack * tmp;					//用于临时存放堆栈最上面的结点（空头结点的next） 
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

