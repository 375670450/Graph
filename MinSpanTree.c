#include "MinSpanTree.h"


int FindMGMin(MGraph * G,int LowCost[]){				//记得要传入待查询的数组 LowCost 
	//找到G中距离当前的树最小距离的点，并返回该点的序号
	int i,j,k;
	int MinCost = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//【复杂度为o（N）】 
		if( LowCost[j] && LowCost[j]<MinCost ){			// 不在树内 && 距离最小 
			MinCost = LowCost[j];
			k = j;
		}
	}
	return k;
}

void PrimMG(MGraph * G){
	char v;
	int i,j,k,parent,root;
	int Parent[MaxVertexNum] = {0};
	int LowCost[MaxVertexNum];		 	//当前树与某个点的直接边的权值（若在树内则为0，无边则为INFINITY） 
	
	printf("Spanning From the Vertex V(V must belong to the Graph):\n");
	scanf("%c%*c",&v);
	root = FindVertexMG(G,v);
	for( i=0; i<G->n; i++){
		LowCost[i] = G->Edges[root][i] ;
	}
	Parent[root] = -1;					//根节点 
	LowCost[root] = 0;
	parent = root;

	for( j=0; j<G->n; j++){				//因为一共只需加入N次顶点即可 
		printf("Visited Vertex: %c \n",G->Vertices[parent]);
		i = FindMGMin(G,LowCost);			//搜索出距离当前树最近的顶点 
		if( i>=0 ){						//如果i>0,即搜索结果为还有未加入树的顶点 
			LowCost[i] = 0;
			Parent[i] = parent;
			parent = i;
			for( k=0; k<G->n; k++){
				//【重要】每次找到一个新的顶点都需要更新其他顶点对于树的距离 
				LowCost[k] = Min(LowCost[k],G->Edges[i][k]);
			}
		}else{
			//这里加的else作用比较特殊（只有非连通图才能进来）
			printf("图非连通\n");
			break; 
		}
	}
	return ;
}

int FindMin(ALGraph * G,int LowCost[]){				//记得要传入待查询的数组 LowCost 
	//找到G中距离当前的树最小距离的点，并返回该点的序号
	int i,j,k;
	int MinCost = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//【复杂度为o（N）】 
		if( LowCost[j] && LowCost[j]<MinCost ){			// 不在树内 && 距离最小 
			MinCost = LowCost[j];
			k = j;
		}
	}
	return k;
}

void PrimALG(ALGraph * G){
	char v;
	int i,j,k,parent,root;
	int Parent[MaxVertexNum] = {0};
	int LowCost[MaxVertexNum];		 	//当前树与某个点的直接边的权值（若在树内则为0，无边则为INFINITY） 
	EdgeNode * edge;
	
	printf("Spanning From the Vertex V(V must belong to the Graph):\n");
	scanf("%c%*c",&v);
	root = FindVertex(G,v);
	edge = G->Adjlist[root].FirstEdge;
	for( i=0; i<G->n; i++){
		LowCost[i] = INFINITY;
	}
	while(edge){
		LowCost[(edge->AdjV)] = edge->Value;
		edge = edge->Next;
	}
	Parent[root] = -1;					//根节点 
	LowCost[root] = 0;
	parent = root;
	for( j=0; j<G->n; j++){				//因为一共只需加入N次顶点即可 
		printf("Visited Vertex: %c \n",G->Adjlist[parent].Vertex);
		i = FindMin(G,LowCost);			//搜索出距离当前树最近的顶点 
		if( i>=0 ){						//如果i>0,即搜索结果为还有未加入树的顶点 
			LowCost[i] = 0;
			Parent[i] = parent;
			parent = i;
			edge = G->Adjlist[i].FirstEdge;	
			while( edge ){				//【重要】每次找到一个新的顶点都需要更新其他顶点对于树的距离 
				k = edge->AdjV;
				LowCost[k] = Min(LowCost[k],edge->Value);
				edge = edge->Next;
			}
		}else{
			//这里加的else作用比较特殊（只有非连通图才能进来）
			printf("图非连通\n");
			break; 
		}
	}
	return ;

}

void KruskalMG(MGraph * G){
	//按权值由小到大的顺序遍历所有边 
	
	return ;
}

void KruskalALG(ALGraph * G){
	char v;
	int i,j,k,parent1,parent2,EdgeNum;
	EdgeNode * edge;
	SetType S[G->n];
	MinHeap H;
	H = (MinHeap)CreateMinHeap();
	int Visited[G->n];
	
	// Initialization
	for(i=0; i<G->n; i++){
		S[i].Data = G->Adjlist[i].Vertex;	//将所有的顶点存入生成树的集合 
		S[i].Parent = -1;					//一开始所有顶点都是一棵独立的树 
		Visited[i] = FALSE;
		edge = G->Adjlist[i].FirstEdge;
		while( edge ){						//将所有的边组成一个最小堆（越上面的元素值越小） 
			MinHeapInsert(H,edge);
			edge = edge->Next;
		}
	}
	
	EdgeNum = 0;
	while( EdgeNum < (G->n) || !IsEmptyMin(H) ){
	//为什么不是找到n-1条边就停下：因为按目前的写法边数的增加次数和点的输出次数保持一致
	//要输出n个点，EdgeNum就必须++ n次【需改进】 
		edge = (EdgeNode*)DeleteMin(H);
		parent1 = SetFind(S,G->n,edge->Vertex);
		parent2 = SetFind(S,G->n,edge->AdjV);
		if( parent1!=parent2 || parent1==-1 ){
			if( !Visited[edge->Vertex] ) {
				printf("Visited Vertex : %c \n",S[edge->Vertex]);
				Visited[edge->Vertex] = TRUE;
				EdgeNum++;
			}
			if( !Visited[edge->AdjV] ) {
				printf("Visited Vertex : %c \n",S[edge->AdjV]);
				Visited[edge->AdjV] = TRUE;
				EdgeNum++;
			}
			SetUnion(S,G->n,edge->Vertex,edge->AdjV);
		}
	}
	if( EdgeNum < G->n ) printf("图不连通\n");
	
	return ;
}



