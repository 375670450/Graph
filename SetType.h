#ifndef SETTYPE_H
#define SETTYPE_H
#include"AllTypeDefinition.h"

//�ö�����ṹ�洢���ϣ�����ÿ����㶼����һ������Ԫ�� 
//ѡ�����е�ĳ��Ԫ����Ϊ���ڵ㣬�����Ϊ���ӽ��
//���������ӽ��ָ�򸸽ڵ㣨�����ж�ĳ��Ԫ�������ļ��ϣ������ڵ�Ϊ-1��ʾ�䱻ѡΪ�������ϵĸ��ڵ㣩 

int SetFind(SetType S[],const int Size,ElementType X);		//������S�в���ֵΪX��Ԫ�ص���������(���ڵ㣩 
void SetUnion(SetType S[],const int Size,ElementType X1,ElementType X2);	//���ϲ����㣨��X2�����ļ��ϲ���X1���������ڣ� 


#endif 
