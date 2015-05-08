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
	printf("Input the Vertex Value(Format:Value <CR>):\n");			//<CR>��ʾ�س�
	for(i=0; i<G->n; i++){
		scanf("%c%*c",&(G->Vertices[i]));
	}
	printf("Input the Edge(Format:Vertex1,Vertex2,EdgeValue <CR>):\n");			//<CR>��ʾ�س�
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
	//����ֵΪV�Ķ�����ı�����ţ����ǵ����ݹ�ģ�ϴ�ʱ����������Ч�ʣ� 
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
		edge->AdjV   = v2;				//�ڽӵ����ŵ�����һ������� 
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
	
	printf("Input the Vertex Value(Format:Value <CR>):\n");			//<CR>��ʾ�س�
	for(i=0; i<G->n; i++){
		scanf("%c&*c",&(G->Adjlist[i].Vertex));
		getchar();
		G->Adjlist[i].FirstEdge = NULL;
	} 
	printf("Input the Edge(Format:Vertex1 Vertex2 EdgeValue <CR>):\n");			//<CR>��ʾ�س�
	for(j=0; j<G->e; j++){
		scanf("%c %c %d%*c",&from,&to,&w);
		InsertEdgeAL(G,from,to,w);
		InsertEdgeAL(G,to,from,w);
	}
	
}

void DFS(ALGraph *G,int i){
	//��ViΪ��������ڽӱ�洢��ͼG����DFS����
	EdgeNode * edge;
	printf("Visit Vertex:%c \n",G->Adjlist[i].Vertex);	//�൱��VisitFunc(),���ʸýڵ� 
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
	for(i=4; i<G->n; i++){		//�����Ϊ��i����㿪ʼ���� 
		if( !Visited[i] ){
			DFS(G,i);		//��Viδ�����ʹ����Vi��ʼDFS����Ҫ����Զ����ͨ������ͼ�� 
		}
	}
	return ;
}

void BFS(ALGraph *G,int i){
	//��ViΪ��������ڽӱ�洢��ͼG����DFS����
	//��Ϊʲôһ��Ҫ��VertexTypeΪ���е�Ԫ�أ��� 
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
	
	for(i=0; i<G->n; i++){	//�ӵ�i����㿪ʼ���й���������� 
		if( !Visited[i] ){
			BFS(G,i);
		}
	}
	return ;
}

	
void ToplogicalSort(ALGraph * G){
	//��������:ÿ���ҵ����Ϊ0�Ķ����¼��ɾ��
	//ÿ��ɾ������ʱ����ڽӵ�����Ƿ��ɴ˱�Ϊ0,ʹ�á����С��洢��ȱ�Ϊ0�Ķ���(�����)�Խ�ʡЧ��
	int i,j,Counter;						//Counter��������������� 
	int InDegree[G->n],TopNum[G->n];		//TopNum����洢��Ԫ�������������� 
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
����: �¼�
��: �
�¼�������֮ǰ�����л��ɡ�
���ʼ������¼��ط�����
��������յ��¼���һ��������

ee(j)���¼�vj���ܷ����ġ����硿ʱ�̡����Ǵӿ�ʼ����v0��vj�ġ����·�����ȡ�
		Ҳ�����˴�vj���������л�����翪ʼʱ�䡣
le(i)���ڱ�֤�������������ڵ�ǰ���£��¼�vi ������������ʱ�̡�
e(k)���ak = < vi ,vj>�����翪ʼʱ�䡣
l(k)���ak = < vi ,vj>������ʼʱ�䡣l(k)-e(k)��ʾ�û��������ӳ�ʱ�� 
Դ�㣺���Ϊ0�Ķ��㡣
��㣺����Ϊ��Ķ��㡣

�ؼ�·��: Ȩֵ֮������·��	
�ؼ��: e(k)=l(k)�Ļ,���йؼ������һ���ؼ�·�� 

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
	int Earliest[G->n],Latest[G->n];		//��������(�¼�)�����翪ʼ�¼�������ʼ�¼�
	
	return ;
}




