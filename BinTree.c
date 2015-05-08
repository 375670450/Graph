#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"Stack.h"
#include"Queue.h"
#define MAXSIZE 100


//V-访问结点，L-向左分支移动，R-向右分支移动 
//二叉树的遍历(按：先序(VLR)，中序(LVR)，后序(LRV)，层序遍历四种
void InOrderTraversal(BinTree BT){
	 //中序遍历：遍历左子树，访问中结点，遍历右子树(其他两种类似，更换三个语句的顺序即可） 
//	if( !IsEmpty(BT->Left) ) Travelsal(BinTree BT->Left); 省略为直接判断BT是否空即可
/*递归算法：	if( BT ){
					InOrderTravelsal(BT->Left);
					printf("%2d",BT->Data);
					InOrderTravelsal(BT->Right);		//这三个语句的顺序类似于汉诺塔问题递归解法 
				} 
*/
//非递归算法：（链栈）
	 Stack * PtrS;
	 PtrS = CreateStack();
	 BinTree T = BT;
	 while( T || !IsEmptyS(PtrS) ){			//循环条件特殊记 
	 	while( T ){ 
	 		Push(PtrS,T);					//注意这里栈内的元素是BinTree类型的
			T = T->Left;					//若是先序遍历则在这里访问T结点(后序遍历则不同，需要二次入栈） 
	 	}
	 	if( !IsEmptyS(PtrS) ){
	 		T = Pop(PtrS);
	 		printf("%d ",T->Data);
	 		T = T->Right;
	 	} 
	 }
	 printf("\n");								//每次输出完全部数据就换一行
	 return ;
}

void PostOrderTraversal(BinTree BT){
	//后序遍历递归算法：
	static int first = 1;
	if( BT ){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		if( first ){
			printf("%d",BT->Data);
			first = 0;
		}else{
			printf(" %d",BT->Data);
		}
	}
//	printf("\n");								//每次输出完全部数据就换一行
//后序遍历的非递归算法	 Stack * PtrS;
//因为较麻烦而不常用	 PtrS = CreateStack();
//						 BinTree T = BT;
//						 while( T || !IsEmpty(PtrS) ){			//循环条件特殊记 
//						 	while( T ){
//						 		T->tag++;
//						 		Push(PtrS,T);					//注意这里栈内的元素是BinTree类型的
//								T = T->Left;					//若是先序遍历则在这里访问T结点(后序遍历则不同，需要二次入栈） 
//						 	}
//						 	if( !IsEmpty(PtrS) ){
//						 		T = Pop(PtrS);
//						 		if( T->tag==2 ) printf("%2d",T->Data);
//						 		else if( T->tag==1 ){
//						 			 T->tag++;
//						 			 Push(PtrS,T);
//								}
//						 		T = T->Right;
//						 	}
//						 }

	return ;
}

void LevelOrderTraversal(BinTree BT){
	//层序遍历算法
	if( BT==NULL ) return ;				//若是空树则返回 
	
	Queue * PtrQ;
	PtrQ = CreateQueue();
	BinTree T;
//	T = BT;			//写成下面这个形式更标准 
	AddQ(PtrQ,BT);
	while( !IsEmptyQ(PtrQ) ){			//循环条件只写队列非空即可 
		T = DeleteQ(PtrQ);
		printf("%d ",T->Data);
		if(T->Left)  AddQ(PtrQ,T->Left);		//因为AddQ远比printf要复杂，因此判断条件 
		if(T->Right) AddQ(PtrQ,T->Right);		//应加在AddQ前面 
	}
	printf("\n");								//每次输出完全部数据就换一行
}

void PreOrderPrintLeaves(BinTree BT){
	if( BT ){
		if( BT->Left==NULL && BT->Right==NULL ){
			printf("%d ",BT->Data);
		}else{ 
			PreOrderPrintLeaves(BT->Left);
			PreOrderPrintLeaves(BT->Right);			
		} 
	}
	printf("\n");								//每次输出完全部数据就换一行
	return ;
} 

int GetHeight(BinTree BT){
	return PostOrderGetHeight(BT);
}

int PostOrderGetHeight(BinTree BT){
	int LeftHeight,RightHeight,MaxHeight;
	if( BT ){
		LeftHeight = PostOrderGetHeight(BT->Left);
		RightHeight = PostOrderGetHeight(BT->Right);
		MaxHeight = LeftHeight>RightHeight? LeftHeight:RightHeight;
		return (MaxHeight+1);						//因为目前MaxHeight只是子树最大高度，需要加上自身结点 
	}else{
		return 0 ;			//子树为空，返回深度 0 
	}
} 

BinTree CreateBinTree(){
	//层序创建，递归算法 
	BinTree BT,T; 
	Queue * PtrQ;
	PtrQ = CreateQueue();
	ElementType Data;
	scanf("%d",&Data);
	if( Data==0 ) return NULL;					//如果输入的是0，返回空树
	else{
		BT = (BinTree)malloc(sizeof(BinTree));
		BT->Data = Data;
		AddQ(PtrQ,BT);
	//以上是根节点的输入 
		while( !IsEmptyQ(PtrQ) ){
			T = DeleteQ(PtrQ);
			scanf("%d",&Data);
			if( Data==0 ){
				T->Left = NULL;
			}else{
				T->Left = (BinTree)malloc(sizeof(BinTree));
				T->Left->Data = Data;
				AddQ(PtrQ,T->Left);
			}
			scanf("%d",&Data);
			if( Data==0 ){
				T->Right = NULL;
			}else{
				T->Right = (BinTree)malloc(sizeof(BinTree));
				T->Right->Data = Data;
				AddQ(PtrQ,T->Right);
			}
		}
	}
	printf("\n");								//每次输出完全部数据就换一行 
	return BT;
} 

BinTree CreateTreeNode(ElementType Data){
	BinTree BT;
	BT = (BinTree)malloc(sizeof(struct TreeNode));
	BT->Data = Data;
	BT->Tag = 0;
	BT->Left = BT->Right = NULL;
	return BT;
}

