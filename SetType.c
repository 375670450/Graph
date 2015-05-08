#include<stdio.h>
#include<stdlib.h>
#include"SetType.h"

int SetFind(SetType S[],const int Size,ElementType X){ 
	//【注意】传入的数组S的每一个元素都是一个SetType型元素（即一个结点） 
	// 此函数返回最终的Parent(所属集合)或自身(当自身为根节点时），找不到X才返回-1 
	// 应该在查找过程中减少树的高度（方法一：路径压缩） 
	int i,j;
	for(i=1;i<=Size;i++){
		if( S[i].Data==X ){
			j = i;
			while(S[i].Parent>0){
				i = S[i].Parent;
			}
			while( j!=i ){
				S[j].Parent = i;
				j = S[j].Parent;
			}
			return i;		//找到所属集合（【若未找到则返回自身下标】，保持返回值必为正） 
		}
	}
	return -1;			//未找到,返回-1
}

void SetUnion(SetType S[],const int Size,ElementType X1,ElementType X2){
	int Root1,Root2;
	Root1 = SetFind(S,Size,X1);				//返回X1所属的集合 
	Root2 = SetFind(S,Size,X2);
	if(Root2>0) S[Root2].Parent = Root1;		//保证找到才合并 
	return ;
}
 

 
