#ifndef STACK_H
#define STACK_H
#include"AllTypeDefinition.h"

//��ջ�Ĳ�����
Stack * CreateStack();						//����һ���ն�ջ�������鲻ͬ����Ҫ����MaxSize 
int IsFullS(Stack * S,int MaxSize); 			//�ж϶�ջ�Ƿ����������򷵻�1(true)�����򷵻�0
void Push(Stack * S,StackElem item);		//��Ԫ��itemѹ���ջ������ջ�����򷵻�������Ϣ
int IsEmptyS(Stack * S);						//�ж϶�ջ�Ƿ�Ϊ�գ����򷵻�1(true)�����򷵻�0
StackElem Pop(Stack * S);					//ɾ��������ջ��Ԫ�ء�����ջΪ�գ����ظ���Ϣ��

#endif
