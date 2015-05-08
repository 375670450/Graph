#include"ShortestPath.h"

int FindMGShort(MGraph * G,int D[],int Arrived[]){				//�ǵ�Ҫ�������ѯ������ LowCost 
	//�ҵ�G�о��뵱ǰ������С����ĵ㣬�����ظõ�����
	int i,j,k;
	int MinDist = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//�����Ӷ�Ϊo��N���� 
		if( !Arrived[j] && D[j] && D[j]<MinDist ){			// δ���� && ������С 
			MinDist = D[j];
			k = j;
		}
	}
	return k;
}

void DijkstraMG(MGraph * G,int v0){
	//�ڽӾ���洢��ͼ���·���㷨 
	//��Prim�㷨ʮ������,����ֱ����Prim�㷨�е�FindMin���� 
	int P[G->n],D[G->n],Arrived[G->n];				//P[]������·���ڽ����ĸ�����,D[]��Ÿ����㵽V0�����·��ֵ 
	int i,j,k,shortest;
	
	// Initialization
	for(i=0; i<G->n; i++){
		Arrived[i] = FALSE;
		P[i] = -1;
		D[i] = INFINITY;
	}
	
	// Update the shortest path of each vertex 
	D[v0] = 0;
	P[v0] = v0;
	Arrived[v0] = 0;
	for(j=0; j<G->n; j++){
		if( G->Edges[v0][j] < D[j] ){
			D[j] = G->Edges[v0][j];
			P[j] = v0;
		}
	}
	
	for(i=1; i<G->n; i++){							//����iֻ�ǿ��ƴ���,��ʵ������ 
		shortest = FindMGShort(G,D,Arrived);
		if( D[shortest] == INFINITY ) break;		//���Ƿ���ͨͼ,���� 
		Arrived[shortest] = TRUE;
		for(j=0; j<G->n; j++){						//Update the shortest path
			if( G->Edges[shortest][j]+D[shortest] < D[j] ){
				P[j] = shortest;
				D[j] = D[(P[j])] + G->Edges[shortest][j];
			}
		}
	}
	
	for(i=0; i<G->n; i++){
		if( i==v0 ) continue;
		printf("P[%d] = %d, D[%d] =%d \n",i,P[i],i,D[i]);
	}
	
	PrintSP(P,9);
	return ;
}

int FindShort(ALGraph * G,int D[],int Arrived[]){				//�ǵ�Ҫ�������ѯ������ LowCost 
	//�ҵ�G�о��뵱ǰ������С����ĵ㣬�����ظõ�����
	int i,j,k;
	int MinDist = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//�����Ӷ�Ϊo��N���� 
		if( !Arrived[j] && D[j] && D[j]<MinDist ){			// δ���� && ������С 
			MinDist = D[j];
			k = j;
		}
	}
	return k;
}

void Dijkstra(ALGraph * G,int v0){
	// �ڽӱ�洢��ͼ���·���㷨(ʱ�临�Ӷ�ΪO(|E|log|V|) 
	int P[G->n],D[G->n],Arrived[G->n];				//P[]������·���ڽ����ĸ�����,D[]��Ÿ����㵽V0�����·��ֵ 
	int i,shortest;
	EdgeNode * edge;
	
	// Initialization
	for(i=0; i<G->n; i++){
		Arrived[i] = FALSE;
		P[i] = -1;
		D[i] = INFINITY;
	}
	
	// Update the shortest path of each vertex 
	D[v0] = 0;
	Arrived[v0] = 0;
	edge = G->Adjlist[v0].FirstEdge;
	while( edge ){
		D[edge->AdjV] = edge->Value;
		P[edge->AdjV] = v0;
		edge = edge->Next;
	}
	
	for(i=1; i<G->n; i++){							//����iֻ�ǿ��ƴ���,��ʵ������ 
		shortest = FindShort(G,D,Arrived);
		if( D[shortest] == INFINITY ) break;		//���Ƿ���ͨͼ,���� 
		Arrived[shortest] = TRUE;
		edge = G->Adjlist[shortest].FirstEdge;
		while( edge ){								//Update the shortest path
			if( edge->Value + D[shortest] < D[edge->AdjV] ){
				D[edge->AdjV] = edge->Value + D[shortest];
				P[edge->AdjV] = shortest;
			}
			edge = edge->Next;						//��Ҫ���Ǹı�ѭ������ 
		}
	}
	
	for(i=0; i<G->n; i++){
		if( i==v0 ) continue;
		printf("P[%d] = %d, D[%d] =%d \n",i,P[i],i,D[i]);
	}
	
	PrintSP(P,9);
	return ;
}

void PrintSP(int P[],int n){
	if( P[n]!=-1 ){
		PrintSP(P,P[n]);
		printf("-->V%d",n);
	}else{
		printf("V%d",n);
	}
	return ;
}

void FloydMG(MGraph * G){
	//	�����ѵ㡿 
	int D[G->n][G->n];			// 	DistanceMatrix
	int P[G->n][G->n];			//	PathMatrix
	int i,j,k;
	//��P[i][j] = k ����k�Ǵ�i��j�����·���ıؾ����� 
	 
	// Construct the Matirx
	for(i=0; i<G->n; i++){
		for(j=0; j<G->n; j++){
			D[i][j] = G->Edges[i][j];
			P[i][j] = i;
		}
		D[i][i] = 0;
	}		//���������ֱ�ӵı�,D[i][j]=INFINITY,P[i][j] = i Ҳ������� 
	
	for(k=0; k<G->n; k++){		//���ؼ�����k��0~N-1����N������(�����Խ���) 
								//ÿ�αȽ�K���˵Ķ����ֱ�Ӿ���(Vi,Vj)��ͨ��K�ļ�Ӿ���(Vi,Vk,Vj) 
		for(i=0; i<G->n; i++){
			for(j=0; j<G->n; j++){
				// ѭ������i��j������������(�����ų� i==k����j==k�����,��Ϊ����һ���������if(��ȨֵΪ����ʱ)) 
				if( D[i][k] + D[k][j] < D[i][j]){		//���ʽ���������·���㷨�кܳ��� 
						//��Ӿ���	  < ֱ�Ӿ��� 
					D[i][j] = D[i][k] + D[k][j];		
					P[i][j] = k;
				}
			}
		}
		for(i=0; i<G->n; i++){
			for(j=0; j<G->n; j++){
				printf("%-3d\t",D[i][j]);
			}
			printf("\n");
		}
		system("Pause");
	}
	
	// Print out the Matrix
	printf("Distance Matrix:\n");
	for(i=0; i<G->n; i++){
		for(j=0; j<G->n; j++){
			printf("%-3d\t",D[i][j]);
		}
		printf("\n");
	}
	printf("Path Matrix:\n");
	for(i=0; i<G->n; i++){
		for(j=0; j<G->n; j++){
			printf("%-3d\t",P[i][j]);
		}
		printf("\n");
	}
}



