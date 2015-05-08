#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MaxHeap.h" 
#define MAXDATA 100


MaxHeap CreateMaxHeap(){
	MaxHeap H = (MaxHeap)malloc(sizeof(struct MaxHeapStruct));
	H->Data = (MaxHeapElem*)malloc(sizeof(MaxHeapElem)*(MAXSIZE+1));		//��Ϊ����Ϊ0��λ�ò��� 
	H->Size = 0;
	H->Capacity = MAXSIZE;
//	memset(H,0,sizeof(HeapElem)*H->Capacity);
	H->Data[0] = MAXDATA;				//����"�ڱ�"Ϊ���ڶ������п���Ԫ�ص�ֵ(��ʵ������) 
	return H;
}

Boolean IsFullMax(MaxHeap H){
	if( H )
		return H->Size == H->Capacity;
	else
		return 0;
}

MaxHeap MaxHeapInsert(MaxHeap H,MaxHeapElem item){
	// ���ѵ㡿����һ��Ԫ�أ���Ҫ��֤��������ȫ��������'��ȫ'�����������е�Ԫ����������ŵ�) 
	//������Ԫ��ֵҲҪ�������ѵ�����,���һ�������Ҫ�ƶ�Ԫ�� 
	//�������������������㣨������ȫ����������һ������Ҫ���Ľ�㣩�ĸ��ڵ㿪ʼ
	//			  ��Ҫ�����Ԫ�����¹����ϲ���. 
	//��ʹԭ������ͬ����Ԫ��Ҳ���Բ��룿�� 
	int i;
	if( item>=H->Data[0] || IsFullMax(H) ){
		printf("Heap Insert Failed. \n");
		return NULL;
	}else{
		H->Size++;							//�����ز��ظ���Ҫ���룬�����ȸ���size 
		i = H->Size;				 
		for( ;H->Data[i/2] < item ;i/=2 ){
			H->Data[i] = H->Data[i/2];
		}
		H->Data[i] = item;					//��item���� 
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
	//�����ѵ㡿ȡ����ɾ�������ڵ��Ԫ��ֵ�����ֵ�� 
	//�����������:�ӡ����ڵ㿪ʼ�����������е����һ��Ԫ�����ϡ����ˡ��²��� 
	// �ǵ� child == parent*2 == H->Size ��ζ�����һ����������� 
	//ʱ�临�Ӷ� O(log N) 
	MaxHeapElem TopElem;
	if( IsEmptyMax(H) ){
		TopElem = 0;
		printf("Heap Delete Failed.\n");
	}else{
		TopElem = H->Data[1];
		int i,del,child,parent;		//i���±� 
/////////////////////////////////�����ˡ�///////////////////////////////////////////////// 
		del = H->Size--;			//del�����Ҫɾ����(���һ��)Ԫ�ص��±� 
		for(child=parent=1 ; parent*2 <= H->Size ; parent=child){
			child = 2*parent;		//�����˳���childһ��ָ������ 
			if( child!=H->Size )	// ���child=size���parent���ֻ��������
				if( H->Data[child] < H->Data[child+1] ){
					child++;		//��childָ��ϴ��Ǹ�������del�Ƚ� 
				} 
			if( H->Data[del] > H->Data[child] ){
				//��Ҫɾ���Ľ���Ԫ�رȵ�ǰ���������ӽ�㶼Ҫ�� 
				break; 
			}else{
				//���ӽ�����Ҫɾ���Ľ��� 
				H->Data[parent] = H->Data[child];	//���ӽ��������� 
			}
		}
		H->Data[parent] = H->Data[del]; 
	}
//////////////////////////////////////////////////////////////////////////////////////////
	return TopElem;
} 

MaxHeap BuildMaxHeap(MaxHeap H){
	//ʱ�临�Ӷ�O(N) 
	//�ӵ�Size/2����㿪ʼ���԰����˽�㼰����ǰ��ĸ������һ���С����¹��ˡ�����
	//ֱ�����ڵ�������
	//��Ҫ������ˣ���Ϊ��Size�ǳ����ʱ�򣬵�Size/2�����������߶ȿ��ܴ���1(�ӽ�㳬��2��) 
	int i,parent,child;
	MaxHeapElem temp;
	for(i=H->Size/2 ; i>0 ; i--){	//�˲�ѭ���������ϣ��ƶ� 
		//���Ե�i�����Ϊ������������ȫ���� 
		for( parent=i ; parent*2<=H->Size ; parent=child ){	//�˲�ѭ�������¹��� 
			child = 2*parent;
			if( child!=H->Size )
				if( H->Data[child] < H->Data[child+1] )
					child++;
			if( H->Data[i] > H->Data[child] ){
				//���ڵ���������ӽ�㣬��� 
				break;
			}else{
				//��Ҫ�Ѵ���Ǹ��ӽ�����������Ѹ��ڵ����������
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

