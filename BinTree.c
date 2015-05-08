#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"Stack.h"
#include"Queue.h"
#define MAXSIZE 100


//V-���ʽ�㣬L-�����֧�ƶ���R-���ҷ�֧�ƶ� 
//�������ı���(��������(VLR)������(LVR)������(LRV)�������������
void InOrderTraversal(BinTree BT){
	 //��������������������������н�㣬����������(�����������ƣ�������������˳�򼴿ɣ� 
//	if( !IsEmpty(BT->Left) ) Travelsal(BinTree BT->Left); ʡ��Ϊֱ���ж�BT�Ƿ�ռ���
/*�ݹ��㷨��	if( BT ){
					InOrderTravelsal(BT->Left);
					printf("%2d",BT->Data);
					InOrderTravelsal(BT->Right);		//����������˳�������ں�ŵ������ݹ�ⷨ 
				} 
*/
//�ǵݹ��㷨������ջ��
	 Stack * PtrS;
	 PtrS = CreateStack();
	 BinTree T = BT;
	 while( T || !IsEmptyS(PtrS) ){			//ѭ����������� 
	 	while( T ){ 
	 		Push(PtrS,T);					//ע������ջ�ڵ�Ԫ����BinTree���͵�
			T = T->Left;					//����������������������T���(���������ͬ����Ҫ������ջ�� 
	 	}
	 	if( !IsEmptyS(PtrS) ){
	 		T = Pop(PtrS);
	 		printf("%d ",T->Data);
	 		T = T->Right;
	 	} 
	 }
	 printf("\n");								//ÿ�������ȫ�����ݾͻ�һ��
	 return ;
}

void PostOrderTraversal(BinTree BT){
	//��������ݹ��㷨��
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
//	printf("\n");								//ÿ�������ȫ�����ݾͻ�һ��
//��������ķǵݹ��㷨	 Stack * PtrS;
//��Ϊ���鷳��������	 PtrS = CreateStack();
//						 BinTree T = BT;
//						 while( T || !IsEmpty(PtrS) ){			//ѭ����������� 
//						 	while( T ){
//						 		T->tag++;
//						 		Push(PtrS,T);					//ע������ջ�ڵ�Ԫ����BinTree���͵�
//								T = T->Left;					//����������������������T���(���������ͬ����Ҫ������ջ�� 
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
	//��������㷨
	if( BT==NULL ) return ;				//���ǿ����򷵻� 
	
	Queue * PtrQ;
	PtrQ = CreateQueue();
	BinTree T;
//	T = BT;			//д�����������ʽ����׼ 
	AddQ(PtrQ,BT);
	while( !IsEmptyQ(PtrQ) ){			//ѭ������ֻд���зǿռ��� 
		T = DeleteQ(PtrQ);
		printf("%d ",T->Data);
		if(T->Left)  AddQ(PtrQ,T->Left);		//��ΪAddQԶ��printfҪ���ӣ�����ж����� 
		if(T->Right) AddQ(PtrQ,T->Right);		//Ӧ����AddQǰ�� 
	}
	printf("\n");								//ÿ�������ȫ�����ݾͻ�һ��
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
	printf("\n");								//ÿ�������ȫ�����ݾͻ�һ��
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
		return (MaxHeight+1);						//��ΪĿǰMaxHeightֻ���������߶ȣ���Ҫ���������� 
	}else{
		return 0 ;			//����Ϊ�գ�������� 0 
	}
} 

BinTree CreateBinTree(){
	//���򴴽����ݹ��㷨 
	BinTree BT,T; 
	Queue * PtrQ;
	PtrQ = CreateQueue();
	ElementType Data;
	scanf("%d",&Data);
	if( Data==0 ) return NULL;					//����������0�����ؿ���
	else{
		BT = (BinTree)malloc(sizeof(BinTree));
		BT->Data = Data;
		AddQ(PtrQ,BT);
	//�����Ǹ��ڵ������ 
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
	printf("\n");								//ÿ�������ȫ�����ݾͻ�һ�� 
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

