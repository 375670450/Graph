#ifndef ALLTYPEDEF_H
#define ALLTYPEDEF_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxVertexNum 100
#define MAXSIZE MaxVertexNum
#define INFINITY 65535
#define VertexType char
#define ElementType VertexType		//���������򼯺ϴ�ŵ����� 
#define StackElem BinTree
#define QueueElem int 
#define EdgeType int
//#define MinHeapElem (EdgeNode*)
#define MaxHeapElem int 
#define HuffmanTreeElem char
#define TRUE 1
#define FALSE 0
#define Max(a,b) (a>b? a:b)
#define Min(a,b) (a>b? b:a)


enum GraphType{ DG,UG,DN,UN };	//D-����U-����G-����ͼ��N-��ͼ����Ȩֵ�� 

int Visited[MaxVertexNum];		//��Ƕ����Ƿ��ѱ����ʣ���ֵ��Ϊ0��������ʱ���Ϊ1 

//�ڽӾ���洢���������ж��ٱ߶��Ứ��n^2�Ŀռ� 
typedef struct {
	VertexType Vertices[MaxVertexNum];				//������Ϣ 
	EdgeType Edges[MaxVertexNum][MaxVertexNum];		//��űߵ�Ȩֵ�������ڱ���ΪINFINITY�� 
	int n,e;		//�������ͱ���
	enum GraphType GType; 
} MGraph;				//MGraph�����ڽӾ���洢��ͼ����
//////////////////////////


//�ڽӱ�洢���� 
typedef struct Node{
	//List of Edges
	int AdjV;		//�ڽӵ���Adjacency Value������ڽӶ������š� 
	int Vertex;
	int Value;
	struct Node * Next;
} EdgeNode;

typedef struct Vertex_Node{
	//List of Vertices
	VertexType Vertex;
	EdgeNode * FirstEdge;
} VertexNode;

typedef VertexNode AdjList[MaxVertexNum];	//�����ڽӱ�����Ϊ���VertexNode������
typedef struct{
	AdjList Adjlist;
	enum GraphType GType;
	int n,e;
} ALGraph; 

///////////////////////

typedef ALGraph Graph;
typedef VertexType Vertex;
typedef int Boolean;

//�������ṹ����
//��ע�⡿����TreeNode����Ϊһ�ֽṹ������������ 
typedef struct TreeNode* BinTree;		//��סBinTree�Ѿ���ָ�룬���ü�* 
typedef BinTree Position;  		//��¼Ŀǰ��λ�ã� 
typedef struct TreeNode{
	ElementType Data;
	int Tag ;			//	���ڼ�¼ѹջ����
	BinTree Left;
	BinTree Right;
} Node; 

//���������Ľṹ���� 
typedef struct HuffmanTreeNode * HuffmanTree;
typedef struct HuffmanTreeNode{
	int Weight;
	int Deepth;
	HuffmanTreeElem Data;
	HuffmanTree Left;
	HuffmanTree Right;
} HuffmanNode;


//��С�ѵ����ݽṹ����(�ѿ��Կ���˳��洢�Ķ������� 

typedef EdgeNode* MinHeapElem;
typedef struct MinHeapStruct* MinHeap;
typedef struct MinHeapStruct{
	MinHeapElem * Data;				//��ע�⡿ָ��(�����ָ�������׵�ַ)���洢��Ԫ�ص����� 
			   						// ��ֱ�������飺��Ϊ��Ҫ�õ��ڴ��С��δȷ�� 
	int Size;						//��ǰԪ�ظ��������±��޹ء� 
	int Capacity;					//�ѵ�������� 
} MinHeap_Struct; 


//���ѵ����ݽṹ����
typedef struct MaxHeapStruct* MaxHeap;
typedef struct MaxHeapStruct{
	MaxHeapElem * Data;				//��ע�⡿ָ��(�����ָ�������׵�ַ)���洢��Ԫ�ص����� 
			   						// ��ֱ�������飺��Ϊ��Ҫ�õ��ڴ��С��δȷ�� 
	int Size;						//��ǰԪ�ظ��������±��޹ء� 
	int Capacity;					//�ѵ�������� 
} MaxHeap_Struct; 



//���е����ݽṹ���Ͷ��壨����ǣ��Ƚ��ر�
//typedef VertexType QueueElem; 				//Ϊʲô�����ú궨�壿 
typedef struct Q_Node{
	QueueElem Data;
	struct Q_Node * Next;
} QNode;

typedef struct {			//�����нṹ 
	QNode * front;			//ָ���ͷ��� 
	QNode * rear;			//ָ���β��� 
} Queue;

//��ջ�����Ͷ���
typedef struct StackNode{ 
	StackElem Data;
	struct StackNode * next ;
} Stack ;


//���ϵ����ݽṹ���Ͷ���
typedef struct{
	ElementType Data;
	int Parent;				//������Parent���-1��������������� 
} SetType; 


#endif
