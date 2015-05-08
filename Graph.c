#include "AllTypeDefinition.h"
#include "Graph.h"

void CreateMGraph(MGraph * G){
	int i,j,k,w;
	char v1,v2;
	G->GType = UN;

	printf("Input the VertexNum and EdgeNum(Format:VertexNum EdgeNum ):\n");
	scanf("%d %d%*c",&(G->n),&(G->e));
	
	for(i=0; i<G->n; i++){
		for(j=0; j<G->n; j++){
			G->Edges[i][j] = INFINITY;
		}	
	}
	printf("Input the Vertex Value(Format:Value <CR>):\n");			//<CR>表示回车
	for(i=0; i<G->n; i++){
		scanf("%c%*c",&(G->Vertices[i]));
	}
	printf("Input the Edge(Format:Vertex1,Vertex2,EdgeValue <CR>):\n");			//<CR>表示回车
	for(j=0; j<G->e; j++){
		scanf("%c %c %d%*c",&v1,&v2,&w);
		i = FindVertexMG(G,v1);
		k = FindVertexMG(G,v2);
		G->Edges[i][k] = w;
		G->Edges[k][i] = w;
	}
}

int FindVertexMG(MGraph * G,VertexType V){
	int i;
	for(i=0; i<G->n; i++){
		if( G->Vertices[i]==V ) break;
	}
	if( i<G->n ) return i;
	else{
		printf("Cannot Find the Vertex %c \n",V);
		return 0;
	}
}

int FindVertex(ALGraph * G,VertexType V){
	//返回值为V的顶点结点的表中序号（但是当数据规模较大时，严重拖慢效率） 
	int i ;
	for(i=0; i<G->n; i++){
		if( G->Adjlist[i].Vertex == V ) break;
	}
	if( i<G->n ) return i;
	else{
		printf("Cannot Find the Vertex %c \n",V);
		return 0;
	}
}


ALGraph * InsertEdgeAL(ALGraph *G,Vertex V1,Vertex V2,int Value){
	int v1,v2;
	v1 = FindVertex(G,V1);
	v2 = FindVertex(G,V2);
	EdgeNode* edge = G->Adjlist[v1].FirstEdge;
	if( edge!=NULL ){
		while( edge->Next ){
			edge = edge->Next ;
		}
	}else{
		G->Adjlist[v1].FirstEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
		edge =  G->Adjlist[v1].FirstEdge;
		edge->Value  = Value;
		edge->Vertex = v1;
		edge->AdjV   = v2;				//邻接点域存放的是另一结点的序号 
		edge->Next   = NULL;
	}
	edge->Next = (EdgeNode*)malloc(sizeof(EdgeNode));
	edge->Next->Vertex = v1;
	edge->Next->AdjV   = v2;
	edge->Next->Value  = Value;
	edge->Next->Next   = NULL;
	return G;
}


void CreateALGraph(ALGraph * G){
	int i,j,k,w;
	G->GType = UN;
	EdgeNode edge;
	char from,to;
	printf("Input the VertexNum and EdgeNum(Format:VertexNum EdgeNum ):\n");
	scanf("%d%d%*c",&(G->n),&(G->e));
	
	printf("Input the Vertex Value(Format:Value <CR>):\n");			//<CR>表示回车
	for(i=0; i<G->n; i++){
		scanf("%c&*c",&(G->Adjlist[i].Vertex));
		getchar();
		G->Adjlist[i].FirstEdge = NULL;
	} 
	printf("Input the Edge(Format:Vertex1 Vertex2 EdgeValue <CR>):\n");			//<CR>表示回车
	for(j=0; j<G->e; j++){
		scanf("%c %c %d%*c",&from,&to,&w);
		InsertEdgeAL(G,from,to,w);
		InsertEdgeAL(G,to,from,w);
	}
	
}

void DFS(ALGraph *G,int i){
	//以Vi为出发点对邻接表存储的图G进行DFS搜索
	EdgeNode * edge;
	printf("Visit Vertex:%c \n",G->Adjlist[i].Vertex);	//相当于VisitFunc(),访问该节点 
	Visited[i] = TRUE;
	for(edge=G->Adjlist[i].FirstEdge; edge; edge=edge->Next){
		if( !Visited[edge->AdjV] ){
			DFS(G,edge->AdjV);
		}
	}
	return ;
}

void DFS_ALG(ALGraph * G){
	int i;
	for(i=0; i<G->n; i++){
		Visited[i] = FALSE;
	}
	for(i=4; i<G->n; i++){		//从序号为第i个结点开始搜索 
		if( !Visited[i] ){
			DFS(G,i);		//若Vi未被访问过则从Vi开始DFS（主要是针对多个连通分量的图） 
		}
	}
	return ;
}

void BFS(ALGraph *G,int i){
	//以Vi为出发点对邻接表存储的图G进行DFS搜索
	//【为什么一定要以VertexType为队列的元素？】 
	int j,k;
	Queue * PtrQ;
	QueueElem Front;
	EdgeNode * edge;
	PtrQ = (Queue*)CreateQueue();
	AddQ(PtrQ,G->Adjlist[i].Vertex);
	while( !IsEmptyQ(PtrQ) ){
		Front = DeleteQ(PtrQ);
		i = FindVertex(G,Front);
		if( !Visited[i] ){
			printf("Visit Vertex:%c \n",G->Adjlist[i].Vertex);
			Visited[i] = TRUE;
			edge = G->Adjlist[i].FirstEdge;
			while( edge ){
				AddQ(PtrQ,G->Adjlist[edge->AdjV]);
				edge = edge->Next;
			}
		}
	}
	return ;
}

void BFS_ALG(ALGraph *G){
	int i;
	for(i=0; i<G->n; i++){
		Visited[i] = FALSE;
	}
	
	for(i=0; i<G->n; i++){	//从第i个结点开始进行广度优先搜索 
		if( !Visited[i] ){
			BFS(G,i);
		}
	}
	return ;
}

	
void ToplogicalSort(ALGraph * G){
	//拓扑排序:每次找到入度为0的顶点记录并删除
	//每次删除顶点时检测邻接点入度是否由此变为0,使用【队列】存储入度变为0的顶点(的序号)以节省效率
	int i,j,Counter;						//Counter控制拓扑序列序号 
	int InDegree[G->n],TopNum[G->n];		//TopNum数组存储各元素拓扑排序后序号 
	Queue * PtrQ;
	EdgeNode * edge; 
	PtrQ = (Queue*)CreateQueue();
	 
	// Initial the InDegree of all Vertices
	for(i=0; i<G->n; i++){
		edge = G->Adjlist[i].FirstEdge;
		while( edge ){
			InDegree[(edge->AdjV)]++;
			edge = edge->Next;
		}
	}
	for(i=0; i<G->n; i++){
		if( InDegree[i]==0 ) AddQ(PtrQ,i);		
	}
	
	Counter = 0;
	while( !IsEmptyQ(PtrQ) ){
		//Delete Vertex
		i = DeleteQ(PtrQ);
		printf("V%d ",i);
		TopNum[i] = ++Counter;			
		edge = G->Adjlist[i].FirstEdge;
		while( edge ){
			InDegree[(edge->AdjV)]--;
			if( (edge->AdjV)==0 ) AddQ(PtrQ,edge->AdjV);
			edge = edge->Next;
		}
	}
	
	return ;
}

int IsCircle(ALGraph * G){
	int isCircle = 0;
	
	
} 


/*
顶点: 事件
边: 活动
事件发生：之前的所有活动完成。
活动开始：起点事件必发生。
活动结束：终点事件不一定发生。

ee(j)：事件vj可能发生的【最早】时刻。它是从开始顶点v0到vj的【最长】路径长度。
		也代表了从vj出发的所有活动的最早开始时间。
le(i)：在保证不延误整个工期的前提下，事件vi 允许发生的最晚时刻。
e(k)：活动ak = < vi ,vj>的最早开始时间。
l(k)：活动ak = < vi ,vj>的最晚开始时间。l(k)-e(k)表示该活动可容许的延迟时间 
源点：入度为0的顶点。
汇点：出度为零的顶点。

关键路径: 权值之和最大的路径	
关键活动: e(k)=l(k)的活动,所有关键活动构成一条关键路径 

*/
ALGraph * CreateAOV(ALGraph * G){
	int i,j;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	G->GType = DN;
 	
 	printf("Input the number of events : ");
 	scanf("%d",&G->n);
 	
}

void CriticalPath(ALGraph * G){
	int i,j,k,n; 
	int Earliest[G->n],Latest[G->n];		//各个顶点(事件)的最早开始事件和最晚开始事件
	
	return ;
}




