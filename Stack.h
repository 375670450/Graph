#ifndef STACK_H
#define STACK_H
#include"AllTypeDefinition.h"

//堆栈的操作集
Stack * CreateStack();						//生成一个空堆栈，与数组不同不需要传入MaxSize 
int IsFullS(Stack * S,int MaxSize); 			//判断堆栈是否已满，是则返回1(true)，否则返回0
void Push(Stack * S,StackElem item);		//将元素item压入堆栈，若堆栈已满则返回已满消息
int IsEmptyS(Stack * S);						//判断堆栈是否为空，是则返回1(true)，否则返回0
StackElem Pop(Stack * S);					//删除并返回栈顶元素。若堆栈为空，返回该信息，

#endif
