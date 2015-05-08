#ifndef ALLTYPEDEF_H
#define ALLTYPEDEF_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxVertexNum 100
#define MAXSIZE MaxVertexNum
#define INFINITY 65535
#define VertexType char
#define ElementType VertexType		//二叉树结点或集合存放的数据 
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


enum GraphType{ DG,UG,DN,UN };	//D-有向，U-无向，G-非网图，N-网图（有权值） 

int Visited[MaxVertexNum];		//标记顶点是否已被访问，初值均为0，被访问时则变为1 

//邻接矩阵存储法：不论有多少边都会花费n^2的空间 
typedef struct {
	VertexType Vertices[MaxVertexNum];				//顶点信息 
	EdgeType Edges[MaxVertexNum][MaxVertexNum];		//存放边的权值（不存在边则为INFINITY） 
	int n,e;		//顶点数和边数
	enum GraphType GType; 
} MGraph;				//MGraph是以邻接矩阵存储的图类型
//////////////////////////


//邻接表存储法： 
typedef struct Node{
	//List of Edges
	int AdjV;		//邻接点域，Adjacency Value【存放邻接顶点的序号】 
	int Vertex;
	int Value;
	struct Node * Next;
} EdgeNode;

typedef struct Vertex_Node{
	//List of Vertices
	VertexType Vertex;
	EdgeNode * FirstEdge;
} VertexNode;

typedef VertexNode AdjList[MaxVertexNum];	//定义邻接表类型为存放VertexNode的数组
typedef struct{
	AdjList Adjlist;
	enum GraphType GType;
	int n,e;
} ALGraph; 

///////////////////////

typedef ALGraph Graph;
typedef VertexType Vertex;
typedef int Boolean;

//二叉树结构定义
//【注意】这里TreeNode是作为一种结构名而非类型名 
typedef struct TreeNode* BinTree;		//记住BinTree已经是指针，不用加* 
typedef BinTree Position;  		//记录目前的位置？ 
typedef struct TreeNode{
	ElementType Data;
	int Tag ;			//	用于记录压栈次数
	BinTree Left;
	BinTree Right;
} Node; 

//哈夫曼树的结构定义 
typedef struct HuffmanTreeNode * HuffmanTree;
typedef struct HuffmanTreeNode{
	int Weight;
	int Deepth;
	HuffmanTreeElem Data;
	HuffmanTree Left;
	HuffmanTree Right;
} HuffmanNode;


//最小堆的数据结构定义(堆可以看作顺序存储的二叉树） 

typedef EdgeNode* MinHeapElem;
typedef struct MinHeapStruct* MinHeap;
typedef struct MinHeapStruct{
	MinHeapElem * Data;				//【注意】指针(必须恒指向数组首地址)：存储堆元素的数组 
			   						// 不直接用数组：因为需要用的内存大小还未确定 
	int Size;						//当前元素个数【与下标无关】 
	int Capacity;					//堆的最大容量 
} MinHeap_Struct; 


//最大堆的数据结构定义
typedef struct MaxHeapStruct* MaxHeap;
typedef struct MaxHeapStruct{
	MaxHeapElem * Data;				//【注意】指针(必须恒指向数组首地址)：存储堆元素的数组 
			   						// 不直接用数组：因为需要用的内存大小还未确定 
	int Size;						//当前元素个数【与下标无关】 
	int Capacity;					//堆的最大容量 
} MaxHeap_Struct; 



//队列的数据结构类型定义（特殊记，比较特别）
//typedef VertexType QueueElem; 				//为什么不能用宏定义？ 
typedef struct Q_Node{
	QueueElem Data;
	struct Q_Node * Next;
} QNode;

typedef struct {			//链队列结构 
	QNode * front;			//指向队头结点 
	QNode * rear;			//指向队尾结点 
} Queue;

//堆栈的类型定义
typedef struct StackNode{ 
	StackElem Data;
	struct StackNode * next ;
} Stack ;


//集合的数据结构类型定义
typedef struct{
	ElementType Data;
	int Parent;				//根结点的Parent存放-1以区别于其他结点 
} SetType; 


#endif
