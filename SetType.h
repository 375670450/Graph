#ifndef SETTYPE_H
#define SETTYPE_H
#include"AllTypeDefinition.h"

//用多叉树结构存储集合，树的每个结点都代表一个集合元素 
//选集合中的某个元素作为父节点，其余均为其子结点
//但其中是子结点指向父节点（便于判断某个元素所属的集合，若父节点为-1表示其被选为所属集合的根节点） 

int SetFind(SetType S[],const int Size,ElementType X);		//在数组S中查找值为X的元素的所属集合(父节点） 
void SetUnion(SetType S[],const int Size,ElementType X1,ElementType X2);	//集合并运算（将X2所属的集合并到X1所属集合内） 


#endif 
