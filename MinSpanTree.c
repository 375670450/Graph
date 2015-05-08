#include "MinSpanTree.h"


int FindMGMin(MGraph * G,int LowCost[]){				//�ǵ�Ҫ�������ѯ������ LowCost 
	//�ҵ�G�о��뵱ǰ������С����ĵ㣬�����ظõ�����
	int i,j,k;
	int MinCost = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//�����Ӷ�Ϊo��N���� 
		if( LowCost[j] && LowCost[j]<MinCost ){			// �������� && ������С 
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
	int LowCost[MaxVertexNum];		 	//��ǰ����ĳ�����ֱ�ӱߵ�Ȩֵ������������Ϊ0���ޱ���ΪINFINITY�� 
	
	printf("Spanning From the Vertex V(V must belong to the Graph):\n");
	scanf("%c%*c",&v);
	root = FindVertexMG(G,v);
	for( i=0; i<G->n; i++){
		LowCost[i] = G->Edges[root][i] ;
	}
	Parent[root] = -1;					//���ڵ� 
	LowCost[root] = 0;
	parent = root;

	for( j=0; j<G->n; j++){				//��Ϊһ��ֻ�����N�ζ��㼴�� 
		printf("Visited Vertex: %c \n",G->Vertices[parent]);
		i = FindMGMin(G,LowCost);			//���������뵱ǰ������Ķ��� 
		if( i>=0 ){						//���i>0,���������Ϊ����δ�������Ķ��� 
			LowCost[i] = 0;
			Parent[i] = parent;
			parent = i;
			for( k=0; k<G->n; k++){
				//����Ҫ��ÿ���ҵ�һ���µĶ��㶼��Ҫ������������������ľ��� 
				LowCost[k] = Min(LowCost[k],G->Edges[i][k]);
			}
		}else{
			//����ӵ�else���ñȽ����⣨ֻ�з���ͨͼ���ܽ�����
			printf("ͼ����ͨ\n");
			break; 
		}
	}
	return ;
}

int FindMin(ALGraph * G,int LowCost[]){				//�ǵ�Ҫ�������ѯ������ LowCost 
	//�ҵ�G�о��뵱ǰ������С����ĵ㣬�����ظõ�����
	int i,j,k;
	int MinCost = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//�����Ӷ�Ϊo��N���� 
		if( LowCost[j] && LowCost[j]<MinCost ){			// �������� && ������С 
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
	int LowCost[MaxVertexNum];		 	//��ǰ����ĳ�����ֱ�ӱߵ�Ȩֵ������������Ϊ0���ޱ���ΪINFINITY�� 
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
	Parent[root] = -1;					//���ڵ� 
	LowCost[root] = 0;
	parent = root;
	for( j=0; j<G->n; j++){				//��Ϊһ��ֻ�����N�ζ��㼴�� 
		printf("Visited Vertex: %c \n",G->Adjlist[parent].Vertex);
		i = FindMin(G,LowCost);			//���������뵱ǰ������Ķ��� 
		if( i>=0 ){						//���i>0,���������Ϊ����δ�������Ķ��� 
			LowCost[i] = 0;
			Parent[i] = parent;
			parent = i;
			edge = G->Adjlist[i].FirstEdge;	
			while( edge ){				//����Ҫ��ÿ���ҵ�һ���µĶ��㶼��Ҫ������������������ľ��� 
				k = edge->AdjV;
				LowCost[k] = Min(LowCost[k],edge->Value);
				edge = edge->Next;
			}
		}else{
			//����ӵ�else���ñȽ����⣨ֻ�з���ͨͼ���ܽ�����
			printf("ͼ����ͨ\n");
			break; 
		}
	}
	return ;

}

void KruskalMG(MGraph * G){
	//��Ȩֵ��С�����˳��������б� 
	
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
		S[i].Data = G->Adjlist[i].Vertex;	//�����еĶ�������������ļ��� 
		S[i].Parent = -1;					//һ��ʼ���ж��㶼��һ�ö������� 
		Visited[i] = FALSE;
		edge = G->Adjlist[i].FirstEdge;
		while( edge ){						//�����еı����һ����С�ѣ�Խ�����Ԫ��ֵԽС�� 
			MinHeapInsert(H,edge);
			edge = edge->Next;
		}
	}
	
	EdgeNum = 0;
	while( EdgeNum < (G->n) || !IsEmptyMin(H) ){
	//Ϊʲô�����ҵ�n-1���߾�ͣ�£���Ϊ��Ŀǰ��д�����������Ӵ����͵�������������һ��
	//Ҫ���n���㣬EdgeNum�ͱ���++ n�Ρ���Ľ��� 
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
	if( EdgeNum < G->n ) printf("ͼ����ͨ\n");
	
	return ;
}



