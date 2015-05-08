#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MinHeap.h" 
#define MINDATA 0

MinHeap CreateMinHeap(){
	// ������ʲô��������ջ�����У������С�ѵȣ�����洢��Ԫ�ظ��ӣ�������ʽҲ��临�ӣ� 
	MinHeap H = malloc(sizeof(MinHeapElem));;
	// ��Ϊʲô�����������������ڴ�ȱһ���� 
	H->Data = (MinHeapElem*)malloc(sizeof(MinHeapElem)*MAXSIZE);
	int i ;
	for( i=0; i<=MAXSIZE; i++){
//		��H->Data[i]��ָ�벻�ö�̬�����ڴ� 
		H->Data[i] = (MinHeapElem)malloc(sizeof(MinHeapElem));	//֮������ i<=MAXSIZE��Ϊ����Ϊ0��λ�ò��� 
	}
	H->Size = 0;
	H->Capacity = MAXSIZE;
	H->Data[0]->Value = MINDATA;				//��Compare Value������"�ڱ�"ΪС�ڶ������п���Ԫ�ص�ֵ(��ʵ������) 
	return H;
}

Boolean IsFullMin(MinHeap H){
	if( H )
		return H->Size == H->Capacity;
	else
		return 0;
}

MinHeap MinHeapInsert(MinHeap H,MinHeapElem item){
	// ���ѵ㡿����һ��Ԫ�أ���Ҫ��֤��С������ȫ��������'��ȫ'�����������е�Ԫ����������ŵ�) 
	//������Ԫ��ֵҲҪ������С�ѵ�����,���һ�������Ҫ�ƶ�Ԫ�� 
	//�������������������㣨������ȫ����������һ������Ҫ���Ľ�㣩�ĸ��ڵ㿪ʼ
	//			  ��Ҫ�����Ԫ�����¹����ϲ���. 
	//��ʹԭ������ͬ����Ԫ��Ҳ���Բ��룿�� 
	int i;
	if( IsFullMin(H) ){	//��Compare Value��
		printf("Heap Insert Failed. \n");
		return NULL;
	}else{
		H->Size++;							//�����ز��ظ���Ҫ���룬�����ȸ���size 
		i = H->Size;				 
		for( ;H->Data[i/2]->Value > item->Value ;i/=2 ){		//��Compare Value�� 
			H->Data[i] = H->Data[i/2];
		}
		H->Data[i] = item;					//��item���� 
	}
	return H;
}

Boolean IsEmptyMin(MinHeap H){
	if( H )
		return H->Size==0;
	else 
		return 1;
}

MinHeapElem DeleteMin(MinHeap H){
	//�����ѵ㡿ȡ����ɾ�������ڵ��Ԫ��ֵ�����ֵ�� 
	//�����������:�ӡ����ڵ㿪ʼ�����������е����һ��Ԫ�����ϡ����ˡ��²��� 
	// �ǵ� child == parent*2 == H->Size ��ζ�����һ����������� 
	//ʱ�临�Ӷ� O(log N) 
	MinHeapElem TopElem;
	if( IsEmptyMin(H) ){
		TopElem->Value = 0;
		printf("Heap Delete Failed.\n");
	}else{
		TopElem = H->Data[1];
		int i,del,child,parent;		//i���±� 
/////////////////////////////////�����ˡ�///////////////////////////////////////////////// 
		del = H->Size--;			//del�����Ҫɾ����(���һ��)Ԫ�ص��±� 
		for(child=parent=1 ; parent*2 <= H->Size ; parent=child){
			child = 2*parent;		//�����˳���childһ��ָ������ 
			if( child!=H->Size )	// ���child=size���parent���ֻ��������
				if( H->Data[child]->Value > H->Data[child+1]->Value ){   //��Compare Value�� 
					child++;		//��childָ���С�Ǹ�������del�Ƚ� 
				} 
			if( H->Data[del]->Value < H->Data[child]->Value ){	//��Compare Value��
				//��Ҫɾ���Ľ���Ԫ�رȵ�ǰ���������ӽ�㶼ҪС 
				break; 
			}else{
				H->Data[parent] = H->Data[child];	//���ӽ��������� 
			}
		}
		H->Data[parent] = H->Data[del]; 
	}
//////////////////////////////////////////////////////////////////////////////////////////
	return TopElem;
} 

MinHeap BuildMinHeap(MinHeap H){
	//������� MinHeapInsert�������ɵ���С�����õ������Ѿ���׼ 
	//ʱ�临�Ӷ�O(N) 
	//�ӵ�Size/2����㿪ʼ���԰����˽�㼰����ǰ��ĸ������һ���С����¹��ˡ�����
	//ֱ�����ڵ�������
	//��Ҫ������ˣ���Ϊ��Size�ǳ����ʱ�򣬵�Size/2�����������߶ȿ��ܴ���1(�ӽ�㳬��2��) 
	int i,parent,child;
	MinHeapElem temp;
	for(i=H->Size/2 ; i>0 ; i--){	//�˲�ѭ���������ϣ��ƶ� 
		//���Ե�i�����Ϊ������������ȫ���� 
		for( parent=i ; parent*2<=H->Size ; parent=child ){	//�˲�ѭ�������¹��� 
			child = 2*parent;
			if( child!=H->Size )
				if( H->Data[child]->Value > H->Data[child+1]->Value )	//��Compare Value��
					child++;
			if( H->Data[i]->Value < H->Data[child]->Value ){			//��Compare Value��
				//���ڵ�С�������ӽ�㣬��� 
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

//void MinHeapPrint(MinHeap H){
//	//LevelOrder
//	int i;
//	for(i=1;i<=H->Size;i++){
//		printf("%c :Deepth = %d ,Weight = %d \n",H->Data[i]->Data,H->Data[i]->Deepth,H->Data[i]->Weight);
//	}
//	printf("\n");
//}

