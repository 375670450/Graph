#include"ShortestPath.h"

int FindMGShort(MGraph * G,int D[],int Arrived[]){				//记得要传入待查询的数组 LowCost 
	//找到G中距离当前的树最小距离的点，并返回该点的序号
	int i,j,k;
	int MinDist = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//【复杂度为o（N）】 
		if( !Arrived[j] && D[j] && D[j]<MinDist ){			// 未到达 && 距离最小 
			MinDist = D[j];
			k = j;
		}
	}
	return k;
}

void DijkstraMG(MGraph * G,int v0){
	//邻接矩阵存储的图最短路径算法 
	//与Prim算法十分类似,可以直接用Prim算法中的FindMin函数 
	int P[G->n],D[G->n],Arrived[G->n];				//P[]存放最短路径邻接于哪个顶点,D[]存放各定点到V0的最短路径值 
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
	
	for(i=1; i<G->n; i++){							//这里i只是控制次数,无实际意义 
		shortest = FindMGShort(G,D,Arrived);
		if( D[shortest] == INFINITY ) break;		//若是非连通图,结束 
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

int FindShort(ALGraph * G,int D[],int Arrived[]){				//记得要传入待查询的数组 LowCost 
	//找到G中距离当前的树最小距离的点，并返回该点的序号
	int i,j,k;
	int MinDist = INFINITY;
	for( k=-1,j=0; j<G->n; j++){					//【复杂度为o（N）】 
		if( !Arrived[j] && D[j] && D[j]<MinDist ){			// 未到达 && 距离最小 
			MinDist = D[j];
			k = j;
		}
	}
	return k;
}

void Dijkstra(ALGraph * G,int v0){
	// 邻接表存储的图最短路径算法(时间复杂度为O(|E|log|V|) 
	int P[G->n],D[G->n],Arrived[G->n];				//P[]存放最短路径邻接于哪个顶点,D[]存放各定点到V0的最短路径值 
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
	
	for(i=1; i<G->n; i++){							//这里i只是控制次数,无实际意义 
		shortest = FindShort(G,D,Arrived);
		if( D[shortest] == INFINITY ) break;		//若是非连通图,结束 
		Arrived[shortest] = TRUE;
		edge = G->Adjlist[shortest].FirstEdge;
		while( edge ){								//Update the shortest path
			if( edge->Value + D[shortest] < D[edge->AdjV] ){
				D[edge->AdjV] = edge->Value + D[shortest];
				P[edge->AdjV] = shortest;
			}
			edge = edge->Next;						//不要忘记改变循环变量 
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
	//	【重难点】 
	int D[G->n][G->n];			// 	DistanceMatrix
	int P[G->n][G->n];			//	PathMatrix
	int i,j,k;
	//若P[i][j] = k 代表k是从i到j的最短路径的必经顶点 
	 
	// Construct the Matirx
	for(i=0; i<G->n; i++){
		for(j=0; j<G->n; j++){
			D[i][j] = G->Edges[i][j];
			P[i][j] = i;
		}
		D[i][i] = 0;
	}		//如果不存在直接的边,D[i][j]=INFINITY,P[i][j] = i 也不会混淆 
	
	for(k=0; k<G->n; k++){		//【关键】用k从0~N-1遍历N个顶点(即划对角线) 
								//每次比较K两端的顶点的直接距离(Vi,Vj)与通过K的间接距离(Vi,Vk,Vj) 
		for(i=0; i<G->n; i++){
			for(j=0; j<G->n; j++){
				// 循环变量i和j用来遍历矩阵(不用排除 i==k或者j==k的情况,因为这样一定不会进入if(在权值为正数时)) 
				if( D[i][k] + D[k][j] < D[i][j]){		//这个式子在求最短路径算法中很常见 
						//间接距离	  < 直接距离 
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



