#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MaxHeap.h" 
#define MAXDATA 100


MaxHeap CreateMaxHeap(){
	MaxHeap H = (MaxHeap)malloc(sizeof(struct MaxHeapStruct));
	H->Data = (MaxHeapElem*)malloc(sizeof(MaxHeapElem)*(MAXSIZE+1));		//因为坐标为0的位置不用 
	H->Size = 0;
	H->Capacity = MAXSIZE;
//	memset(H,0,sizeof(HeapElem)*H->Capacity);
	H->Data[0] = MAXDATA;				//定义"哨兵"为大于堆中所有可能元素的值(非实际数据) 
	return H;
}

Boolean IsFullMax(MaxHeap H){
	if( H )
		return H->Size == H->Capacity;
	else
		return 0;
}

MaxHeap MaxHeapInsert(MaxHeap H,MaxHeapElem item){
	// 【难点】插入一个元素，既要保证最大堆是完全二叉树（'完全'体现在数组中的元素是连续存放的) 
	//各结点的元素值也要满足最大堆的性质,因此一般情况下要移动元素 
	//【解决方法】从新增结点（保持完全二叉树，下一个即将要填充的结点）的父节点开始
	//			  用要插入的元素向下过滤上层结点. 
	//即使原来存在同样的元素也可以插入？？ 
	int i;
	if( item>=H->Data[0] || IsFullMax(H) ){
		printf("Heap Insert Failed. \n");
		return NULL;
	}else{
		H->Size++;							//无论重不重复都要插入，所以先更新size 
		i = H->Size;				 
		for( ;H->Data[i/2] < item ;i/=2 ){
			H->Data[i] = H->Data[i/2];
		}
		H->Data[i] = item;					//将item插入 
	}
	return H;
}

Boolean IsEmptyMax(MaxHeap H){
	if( H )
		return H->Size==0;
	else 
		return 1;
}

MaxHeapElem DeleteMax(MaxHeap H){
	//【重难点】取出（删除）根节点的元素值（最大值） 
	//【解决方法】:从【根节点开始】，用最大堆中的最后一个元素向上【过滤】下层结点 
	// 记得 child == parent*2 == H->Size 意味着最后一个结点是左结点 
	//时间复杂度 O(log N) 
	MaxHeapElem TopElem;
	if( IsEmptyMax(H) ){
		TopElem = 0;
		printf("Heap Delete Failed.\n");
	}else{
		TopElem = H->Data[1];
		int i,del,child,parent;		//i作下标 
/////////////////////////////////【过滤】///////////////////////////////////////////////// 
		del = H->Size--;			//del存放需要删除的(最后一个)元素的下标 
		for(child=parent=1 ; parent*2 <= H->Size ; parent=child){
			child = 2*parent;		//这样乘出来child一定指向左结点 
			if( child!=H->Size )	// 如果child=size则此parent结点只有左结点了
				if( H->Data[child] < H->Data[child+1] ){
					child++;		//令child指向较大那个方便与del比较 
				} 
			if( H->Data[del] > H->Data[child] ){
				//需要删除的结点的元素比当前结点的两个子结点都要大 
				break; 
			}else{
				//有子结点比需要删除的结点大 
				H->Data[parent] = H->Data[child];	//把子结点填充上来 
			}
		}
		H->Data[parent] = H->Data[del]; 
	}
//////////////////////////////////////////////////////////////////////////////////////////
	return TopElem;
} 

MaxHeap BuildMaxHeap(MaxHeap H){
	//时间复杂度O(N) 
	//从第Size/2个结点开始，对包括此结点及其他前面的各结点逐一进行【向下过滤】操作
	//直到根节点过滤完毕
	//需要两层过滤：因为当Size非常大的时候，第Size/2个结点的子树高度可能大于1(子结点超过2个) 
	int i,parent,child;
	MaxHeapElem temp;
	for(i=H->Size/2 ; i>0 ; i--){	//此层循环是向左（上）移动 
		//对以第i个结点为根的树向下完全过滤 
		for( parent=i ; parent*2<=H->Size ; parent=child ){	//此层循环是向下过滤 
			child = 2*parent;
			if( child!=H->Size )
				if( H->Data[child] < H->Data[child+1] )
					child++;
			if( H->Data[i] > H->Data[child] ){
				//根节点大于两个子结点，完成 
				break;
			}else{
				//需要把大的那个子结点拉上来，把根节点继续往下送
	 			H->Data[parent] = H->Data[child];
			}
		}
		H->Data[parent] = H->Data[i];
	}
	return H;
}

void MaxHeapPrint(MaxHeap H){
	//LevelOrder
	int i;
	for(i=1;i<=H->Size;i++){
		printf("%d ",H->Data[i]);
	}
	printf("\n");
}

